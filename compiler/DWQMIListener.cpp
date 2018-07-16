/***********************************************************************************
 * Copyright (c) 2018, UT-Battelle
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
 *   Initial implementation - Alex McCaskey
 *
 **********************************************************************************/
#include <iostream>
#include <IRProvider.hpp>
#include <boost/math/constants/constants.hpp>
#include "exprtk.hpp"
#include "DWQMIListener.hpp"
#include "DWKernel.hpp"
#include "DWQMI.hpp"

#include "XACC.hpp"

using namespace dwqmi;
//using symbol_table_t = exprtk::symbol_table<double>;
//using expression_t = exprtk::expression<double>;
//using parser_t = exprtk::parser<double>;

namespace xacc {
namespace quantum {

constexpr static double pi = boost::math::constants::pi<double>();

DWQMIListener::DWQMIListener() {
	f = std::make_shared<DWKernel>("main"); 
}

std::shared_ptr<Function> DWQMIListener::getKernel() {
	return f;
}

        
void DWQMIListener::enterInst(dwqmi::DWQMIParser::InstContext *ctx) {

	std::shared_ptr<xacc::Instruction> instruction;

	std::vector<int> qubits;

	std::vector<InstructionParameter> params;

	std::string gateName;

	xacc::info("HELLO: "+ ctx->INT(0)->getText());

	instruction = std::make_shared<DWQMI>(std::stoi(ctx->INT(0)->getText()), std::stoi(ctx->INT(1)->getText()), std::stod(ctx->real()->getText()));
        
	std::cout << "hi: " << instruction->toString("") << "\n";
    	f->addInstruction(instruction);
    
}

}
}
