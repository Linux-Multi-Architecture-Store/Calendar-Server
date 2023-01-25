//
// Created by 秦子若 on 2023/1/25.
//

#ifndef CALENDARSERVER_PYTHONTEST_H
#define CALENDARSERVER_PYTHONTEST_H

#include "string"
#include <tuple>

namespace CSabout {
    int TestPython();

    int PrintCompilerInfo();

    std::string GetTargetSystem();

    std::string GetSystemArch(std::string target_system);

    std::string GetCompilerVersion(std::string target_system);

    std::string GetCompilerType();

    std::tuple<std::string, std::string, std::string> GetCompiledDate();
}

#endif //CALENDARSERVER_PYTHONTEST_H