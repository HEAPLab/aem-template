/**
 *       @file  AEMTemplate_main.cc
 *      @brief  The AEMTemplate BarbequeRTRM application
 *
 * Description: Template sources for Adaptive Execution Model integrated applications
 *
 *     @author  Giuseppe Massari <giuseppe.massari@polimi.it>
 *
 *     Company  Politecnico di Milano
 *   Copyright  Copyright (c) 2020
 *
 * This source code is released for free distribution under the terms of the
 * GNU General Public License as published by the Free Software Foundation.
 * =====================================================================================
 */

#include <libgen.h>
#include <iostream>
#include <memory>


#include "AEMTemplate_exc.h"

using namespace std;

int main(int argc, char *argv[]) 
{
	RTLIB_Services_t *rtlib;
	auto ret = RTLIB_Init(basename(argv[0]), &rtlib);
	if (ret != RTLIB_OK) {
		cerr << "ERROR: Unable to init RTLib (Did you start the BarbequeRTRM daemon?)" << endl;
		return RTLIB_ERROR;
	}
	assert(rtlib);

	std::string recipe("aem-template");
	cout << "INFO: Registering EXC with recipe " << recipe << endl;
	auto pexc = std::make_shared<AEMTemplate>("AEMTemplate", recipe, rtlib);
	if (!pexc->isRegistered()) {
		cerr << "ERROR: Register failed (missing the recipe file?)" << endl;
		return RTLIB_ERROR;
	}

	cout << "INFO: Starting EXC control thread " << endl;
	pexc->Start();

	cout << "INFO: Waiting for the EXC termination " << endl;
	pexc->WaitCompletion();

	cout << "INFO: Terminated. " << endl;
	return EXIT_SUCCESS;
}

