/**
 *       @file  AEMTemplate_exc.h
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

#ifndef AEM_TEMPLATE_EXC_H_
#define AEM_TEMPLATE_EXC_H_

#include <bbque/bbque_exc.h>

using bbque::rtlib::BbqueEXC;

class AEMTemplate : public BbqueEXC {

public:

	AEMTemplate(std::string const & name,
		    std::string const & recipe,
		    RTLIB_Services_t *rtlib);

private:

	RTLIB_ExitCode_t onSetup();
	RTLIB_ExitCode_t onConfigure(int8_t awm_id);
	RTLIB_ExitCode_t onRun();
	RTLIB_ExitCode_t onMonitor();
	RTLIB_ExitCode_t onSuspend();
	RTLIB_ExitCode_t onRelease();
};

#endif // AEM_TEMPLATE_EXC_H_
