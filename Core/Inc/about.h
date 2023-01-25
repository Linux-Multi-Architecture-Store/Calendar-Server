//
// Created by 秦子若 on 2023/1/25.
//

#ifndef CALENDARSERVER_PYTHONTEST_H
#define CALENDARSERVER_PYTHONTEST_H

#include "string"

namespace CSabout {
    int TestPython();

    int PrintCompilerInfo();

    std::string GetTargetSystem();

    std::string GetSystemArch(std::string target_system);
}

#endif //CALENDARSERVER_PYTHONTEST_H