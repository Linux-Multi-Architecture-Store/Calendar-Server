#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
#include <clocale>
#include "about.h"
#include <Python.h>

namespace CSabout {
    int TestPython() {
        std::cout << "This is a Python test." << std::endl;

        Py_Initialize();

        PyRun_SimpleString("from time import time,ctime\n" "print('Today is', ctime(time()))\n");

        Py_FinalizeEx();

        auto numbers = 123;
        std::cout << "Test C++11 functons." << std::endl;
        std::cout << numbers << std::endl;

        setlocale(LC_ALL, "");
        std::ios::sync_with_stdio(false);

        wchar_t wstr[] = L"你能输出中文？";
        char str[] = "你能输出中文？";

        std::wcout << wstr << std::endl;
        wprintf(L"%ls\n", wstr);

        std::cout << str << std::endl;
        printf("%s\n", str);

        return 0;
    }

/**
作者：Pluto Hades
链接：https://www.zhihu.com/question/40907940/answer/89216884
来源：知乎
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */
    int PrintCompilerInfo() {
        std::cout << "Compilation date:" << __DATE__ << std::endl;
        std::cout << "Compilation time:" << __TIME__ << std::endl;
        std::cout << "Compilation time stamp:" << __TIMESTAMP__ << std::endl;

        std::string target_system = GetTargetSystem();

        std::stringstream ss_full_version;

        if (target_system == "Windows") {
            #if defined(_MSC_FULL_VER)
                ss_full_version << _MSC_FULL_VER;
            #else
                ss_full_version << "Unknown";
            #endif
        } else if (target_system == "Unix") {
            #if defined(__VERSION__)
                ss_full_version << __VERSION__;
            #else
                ss_full_version << "Unknown";
            #endif
        } else {
            ss_full_version << "Unknown";
        }

        std::string full_version = ss_full_version.str();

        std::string target_platform = GetSystemArch(target_system);

#if defined(_MSC_BUILD)
        std::stringstream BUILD_INFO;
        BUILD_INFO << _MSC_BUILD;
        std::string build_info = BUILD_INFO.str();
#else
        std::string build_info = "Unknown";
#endif
        std::cout << "C/C++ Optimizing Compiler Version: " << full_version << " " << build_info << " for "
                  << target_platform << " On " << GetTargetSystem() << std::endl;
        return EXIT_SUCCESS;
    }

    std::string GetTargetSystem() {
#if defined(_MSC_VER)
        return "Windows";
#elif defined(__unix__)
        return "Unix";
#else
        return "Unknown";
#endif
    }

    std::string GetSystemArch(std::string target_system) {
        std::string target_platform;
        if (target_system == "Windows") {
            #if defined(_M_ALPHA)
                    target_platform = "DEC ALPHA";
            #elif defined(_M_AMD64) || defined(_M_X64) || defined( _WIN64)
                    target_platform = "x64";
            #elif defined(_M_IX86)
                    target_platform = "x86";
            #elif defined(_M_IA64)
                    target_platform = "ia64";
            #elif defined(_M_MPPC)
                    target_platform = "Power PC";
            #elif defined(_M_MRX000)
                    target_platform = "MIPS";
            #elif defined(_M_ARM)
                    std::stringstream arm_version;
                    arm_version << "ARMv" << _M_ARM;
            #if defined(_M_ARMT)
                    arm_version << " thumb mode";
            #endif
                    target_platform = arm_version.str();
            #else
                    target_platform = "Unknown";
            #endif
        } else if (target_system == "Unix") {
            #if defined(__amd64)
                target_platform = "x64";
            #else
                target_platform = "Unknown";
            #endif
        } else {
            target_platform = "Unknown";
        }
        return target_platform;
    }
}

