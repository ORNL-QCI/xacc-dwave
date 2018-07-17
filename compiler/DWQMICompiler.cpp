/***********************************************************************************
 * Copyright (c) 2017, UT-Battelle
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of the xacc nor the
 *     names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Contributors:
 *   Initial API and implementation - Alex McCaskey
 *
 **********************************************************************************/
#include <regex>
#include <boost/algorithm/string.hpp>
#include "DWQMICompiler.hpp"
#include "DWKernel.hpp"
#include "RuntimeOptions.hpp"
#include "AQCAcceleratorBuffer.hpp"

#include "DWQMIListener.hpp"
#include "DWQMILexer.h"

using namespace antlr4;
using namespace dwqmi;

namespace xacc {

namespace quantum {

std::shared_ptr<IR> DWQMICompiler::compile(const std::string& src,
		std::shared_ptr<Accelerator> acc) {

	auto hardwareGraph = acc->getAcceleratorConnectivity();
	std::set<int> qubits;
	std::vector<std::shared_ptr<DWQMI>> instructions;
	int nHardwareVerts = hardwareGraph->order();

	// Set the Kernel Source code
	auto first = src.find("{")+1;
	auto last = src.find_last_of("}");
	kernelSource = src.substr (first,last-first);

	xacc::info("Source:\n" + kernelSource);

    // Get the function name
    std::vector<std::string> lines, fLineSpaces, fLineCommas;    
	boost::split(lines, src, boost::is_any_of("\n"));
	auto functionLine = lines[0];
	boost::split(fLineSpaces, functionLine, boost::is_any_of(" "));
	auto fName = fLineSpaces[1];
	boost::trim(fName);
	fName = fName.substr(0, fName.find_first_of("("));
    boost::split(fLineCommas, functionLine, boost::is_any_of(","));
	std::vector<InstructionParameter> params;
	for (int i = 1; i < fLineCommas.size(); i++) {
		boost::trim(fLineCommas[i]);
		auto arg = fLineCommas[i];
		std::vector<std::string> splitSpace;
		if (boost::contains(arg, ")")) {
			arg = arg.substr(0, arg.find_first_of(")"));
		}

		boost::split(splitSpace, arg, boost::is_any_of(" "));

		arg = splitSpace[1];

		InstructionParameter p(arg);
		params.push_back(p);
	}

    ANTLRInputStream input(kernelSource);
    DWQMILexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    DWQMIParser parser(&tokens);
    parser.removeErrorListeners();
    parser.addErrorListener(new DWQMIErrorListener());
    
    tree::ParseTree *tree = parser.mainprog();
    DWQMIListener listener(fName, params);
    tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);

	// Here we assume, there is just one allocation
	// of qubits for the D-Wave -- all of them.
	auto bufName = acc->getAllocatedBufferNames()[0];
	auto buffer = acc->getBuffer(bufName);
	std::shared_ptr<AQCAcceleratorBuffer> aqcBuffer = std::dynamic_pointer_cast<AQCAcceleratorBuffer>(buffer);
	if (!aqcBuffer) {
		xacc::error("Invalid AcceleratorBuffer passed to DW QMI Compiler. Must be an AQCAcceleratorBuffer.");
	}

    // Get the constructed DW Kernel
    auto dwKernel = listener.getKernel();

	// Now we have a qubits set. If we used 0-N qubits,
	// then this set size will be N, but if we skipped some
	// bits, then it will be < N. Get the maximum int in this set
	// so we can see if any were skipped.
	int maxBitIdx = listener.maxBitIdx; 
	maxBitIdx++;

	// Create a graph representation of the problem
	auto problemGraph = std::make_shared<DWGraph>(maxBitIdx);
	for (auto inst : instructions) {
        if (inst->name() == "dw-qmi") {
		    auto qbit1 = inst->bits()[0];
		    auto qbit2 = inst->bits()[1];
		    if (qbit1 == qbit2) {
		    	problemGraph->setVertexProperties(qbit1, 1.0);
		    } else {
		    	problemGraph->addEdge(qbit1, qbit2,
		    			1.0);
		    }
        }
	}

    // Embed the problem
	Embedding embedding;
	std::string embAlgoStr = "cmr";
	if (xacc::optionExists("dwave-load-embedding")) {
		std::ifstream ifs(xacc::getOption("dwave-load-embedding"));
		embedding.load(ifs);
	} else {
		auto algoStr = xacc::optionExists("dwave-embedding") 
                        ? xacc::getOption("dwave-embedding") : embAlgoStr; 
		auto embeddingAlgorithm =
				xacc::getService<EmbeddingAlgorithm>(algoStr);

		// Compute the minor graph embedding
		embedding = embeddingAlgorithm->embed(problemGraph, hardwareGraph);

		if (xacc::optionExists("dwave-persist-embedding")) {
			auto fileName = xacc::getOption("dwave-persist-embedding");
			std::ofstream ofs(fileName);
			embedding.persist(ofs);
		}
	}

	// Add the embedding to the AcceleratorBuffer
	aqcBuffer->setEmbedding(embedding);

	// Create and return the IR
	auto ir = std::make_shared<DWIR>();
	ir->addKernel(dwKernel);
	return ir;
}

std::shared_ptr<IR> DWQMICompiler::compile(const std::string& src) {
	xacc::error("Cannot compile D-Wave program without "
			"information about Accelerator connectivity.");
}

}

}
