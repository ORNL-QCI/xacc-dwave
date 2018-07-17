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
#ifndef QUANTUM_GATE_ACCELERATORS_DWACCELERATOR_HPP_
#define QUANTUM_GATE_ACCELERATORS_DWACCELERATOR_HPP_

#include "RemoteAccelerator.hpp"
#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>
#include "DWKernel.hpp"
#include "DWQMI.hpp"
#include "AQCAcceleratorBuffer.hpp"

#define RAPIDJSON_HAS_STDSTRING 1

#include "rapidjson/prettywriter.h"
#include "rapidjson/document.h"

using namespace rapidjson;
using namespace xacc;

namespace xacc {
namespace quantum {

/**
 * Wrapper for information related to the remote
 * D-Wave solver.
 */
struct DWSolver {
	std::string name;
	std::string description;
	double jRangeMin;
	double jRangeMax;
	double hRangeMin;
	double hRangeMax;
	int nQubits;
	std::vector<std::pair<int,int>> edges;
};

/**
 * The DWAccelerator is an XACC Accelerator that
 * takes D-Wave IR and executes the quantum machine
 * instructions via remote HTTP invocations.
 */
class DWAccelerator : public RemoteAccelerator {
public:

	/**
	 * The constructor
	 */
	DWAccelerator() : RemoteAccelerator() {}
	DWAccelerator(std::shared_ptr<Client> client) : RemoteAccelerator(client) {}

	/**
	 * Create, store, and return an AcceleratorBuffer with the given
	 * variable id string and of the given number of bits.
	 * The string id serves as a unique identifier
	 * for future lookups and reuse of the AcceleratorBuffer.
	 *
	 * @param varId
	 * @param size
	 * @return
	 */
	std::shared_ptr<AcceleratorBuffer> createBuffer(const std::string& varId,
			const int size);

	/**
	 * Return true if this Accelerator can allocated
	 * NBits number of bits.
	 * @param NBits
	 * @return
	 */
	virtual bool isValidBufferSize(const int NBits);

	/**
	 * Return the graph structure for this Accelerator.
	 *
	 * @return connectivityGraph The graph structure of this Accelerator
	 */
	virtual std::shared_ptr<AcceleratorGraph> getAcceleratorConnectivity();

	virtual const std::string processInput(
			std::shared_ptr<AcceleratorBuffer> buffer,
			std::vector<std::shared_ptr<Function>> functions);

	/**
	 * take response and create
	 */
	virtual std::vector<std::shared_ptr<AcceleratorBuffer>> processResponse(
			std::shared_ptr<AcceleratorBuffer> buffer,
			const std::string& response);

	virtual std::vector<std::shared_ptr<AcceleratorBuffer>> execute(
			std::shared_ptr<AcceleratorBuffer> buffer,
			const std::vector<std::shared_ptr<Function>> functions) {
		int counter = 0;
		std::vector<std::shared_ptr<AcceleratorBuffer>> tmpBuffers;
		for (auto f : functions) {
			auto tmpBuffer = createBuffer(
					buffer->name() + std::to_string(counter), buffer->size());
			RemoteAccelerator::execute(tmpBuffer, f);
			tmpBuffers.push_back(tmpBuffer);
			counter++;
		}

		return tmpBuffers;
	}


	/**
	 * This Accelerator models QPU Gate accelerators.
	 * @return
	 */
	virtual AcceleratorType getType() {
		return AcceleratorType::qpu_aqc;
	}

	/**
	 * We have no need to transform the IR for this Accelerator,
	 * so return an empty list, for now.
	 * @return
	 */
	virtual std::vector<std::shared_ptr<IRTransformation>> getIRTransformations() {
		std::vector<std::shared_ptr<IRTransformation>> v;
		return v;
	}

	/**
	 * Return all relevant RigettiAccelerator runtime options.
	 * Users can set the api-key, execution type, and number of triels
	 * from the command line with these options.
	 */
	virtual std::shared_ptr<options_description> getOptions() {
		auto desc = std::make_shared<options_description>(
				"D-Wave Accelerator Options");
		desc->add_options()("dwave-api-key", value<std::string>(),
				"Provide the D-Wave API key. This is used if "
						"$HOME/.dwave_config is not found")("dwave-api-url",
				value<std::string>(), "The D-Wave SAPI URL, "
						"https://qubist.dwavesys.com/sapi "
						"used by default.")("dwave-solver",
				value<std::string>(), "The name of the solver to run on.")
				("dwave-num-reads", value<std::string>(), "The number of executions on the chip for the given problem.")
				("dwave-anneal-time", value<std::string>(), "The time to evolve the chip - an integer in microseconds.")
				("dwave-thermalization", value<std::string>(), "The thermalization...")
				("dwave-list-solvers", "List the available solvers at the Qubist URL.")
                ("dwave-solve-type", value<std::string>(), "The solve type, qubo or ising");
		return desc;
	}

	virtual bool handleOptions(variables_map& map) {
		if (map.count("dwave-list-solvers")) {
			initialize();

			for (auto s : availableSolvers) {
				xacc::info("Available D-Wave Solver: " + std::string(s.first));
			}
			return true;
		}
		return false;
	}

	/**
	 * Initialize this DWAccelerator with information
	 * about the remote Qubist solvers
	 */
	virtual void initialize();

	/**
	 * Create and return an AQCAcceleratorBuffer of size
	 * dictated by the current solver being used.
	 *
	 * @param varId The name of this buffer
	 * @return buffer The AcceleratorBuffer
	 */
	virtual std::shared_ptr<AcceleratorBuffer> createBuffer(
				const std::string& varId);

	virtual const std::string name() const {
		return "dwave";
	}

	virtual const std::string description() const {
		return "The D-Wave Accelerator executes Ising Hamiltonian parameters "
				"on a remote D-Wave QPU.";
	}

	/**
	 * The destructor
	 */
	virtual ~DWAccelerator() {}

protected:

	/**
	 * Reference to the D-Wave API Token
	 */
	std::string apiKey;

	/**
	 * Reference to the remote D-Wave Qubist URL
	 */
	std::string url;

	/**
	 * Reference to the mapping of solver names
	 * to Solver Type.
	 */
	std::map<std::string, DWSolver> availableSolvers;

	/**
	 * Private utility to search for the D-Wave
	 * API key in $HOME/.dwave_config, $DWAVE_CONFIG,
	 * or --dwave-api-key command line arg
	 */
	void searchAPIKey(std::string& key, std::string& url);

	/**
	 * Private utility to search for key in the config
	 * file.
	 */
	void findApiKeyInFile(std::string& key, std::string& url, boost::filesystem::path &p);

};

}
}




#endif
