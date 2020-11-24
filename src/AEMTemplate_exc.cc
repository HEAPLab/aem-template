/**
 *       @file  AEMTemplate_exc.cc
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


#include "AEMTemplate_exc.h"
#include <iostream>

using namespace std;

AEMTemplate::AEMTemplate(std::string const & name,
		std::string const & recipe,
		RTLIB_Services_t *rtlib) :
	BbqueEXC(name, recipe, rtlib, RTLIB_LANG_CPP) 
{
	cout << "New AEMTemplate::AEMTemplate() UID=" << GetUniqueID() << endl;

	// NOTE: since RTLib 1.1 the derived class construct should be used
	// mainly to specify instantiation parameters. All resource
	// acquisition, especially threads creation, should be palced into the
	// new onSetup() method.
}

RTLIB_ExitCode_t AEMTemplate::onSetup() 
{
	// This is just an empty method in the current implementation of this
	// testing application. However, this is intended to collect all the
	// application specific initialization code, especially the code which
	// acquire system resources (e.g. thread creation)
	cout << "AEMTemplate::onSetup()" << endl;

	return RTLIB_OK;
}

RTLIB_ExitCode_t AEMTemplate::onConfigure(int8_t awm_id) 
{
	int32_t proc_nr;    // nr. of CPU cores 
	int32_t proc_quota; // CPU quota (e.g. quota = 235% -> 3 CPU cores)
	int32_t acc, gpu;
	GetAssignedResources(PROC_ELEMENT, proc_quota);
	GetAssignedResources(PROC_NR, proc_nr);
	GetAssignedResources(GPU, acc);
	GetAssignedResources(ACCELERATOR, acc);

	cout << "AEMTemplate::onConfigure(): proc_nr= " << proc_nr << endl;

	return RTLIB_OK;
}

RTLIB_ExitCode_t AEMTemplate::onRun() {
	RTLIB_WorkingModeParams_t const wmp = WorkingModeParams();

	// Example: return after 5 cycles
	if (Cycles() >= 5)
		return RTLIB_EXC_WORKLOAD_NONE;

	cout << "AEMTemplate::onRun(): Hello AEM! cycle="<< Cycles() << endl;

	return RTLIB_OK;
}

RTLIB_ExitCode_t AEMTemplate::onMonitor() 
{
	cout << "AEMTemplate::onMonitor(): CPS=" << GetCPS() << endl;

	return RTLIB_OK;
}

RTLIB_ExitCode_t AEMTemplate::onSuspend() 
{
	cout << "AEMTemplate::onMonitor()" << GetCPS() << endl;

	return RTLIB_OK;
}

RTLIB_ExitCode_t AEMTemplate::onRelease() 
{
	cout << "AEMTemplate::onRelease()" << endl;

	return RTLIB_OK;
}
