#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <QDebug>
#include "about.h"

namespace CSabout {
    int PrintCompilerInfo() {
        auto times = GetCompiledDate();

        qDebug() << "Compilation date:" << std::get<0>(times).c_str();
        qDebug() << "Compilation time:" << std::get<1>(times).c_str();
        qDebug() << "Compilation time stamp:" << std::get<2>(times).c_str();

        std::string compiler = GetCompilerType();
        std::string target_system = GetTargetSystem();

        std::string full_version = GetCompilerVersion(target_system);

        std::string target_platform = GetSystemArch(target_system);

        qDebug() << "C/C++ Optimizing Compiler Version:" << compiler.c_str() << full_version.c_str() << "for" << target_platform.c_str() << "On" << GetTargetSystem().c_str();
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

    std::string GetCompilerVersion(std::string target_system) {
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
         return ss_full_version.str();
    }

    std::string GetCompilerType() {
        #if defined(_MSC_BUILD)
            return "MSVC";
        #elif defined(__GNUC__) || defined(__GNUG__)
            return "GCC";
        #elif defined(__clang__)
            return "Clang";
        #else
            return "Unknown";
        #endif
    }

    std::tuple<std::string, std::string, std::string> GetCompiledDate() {
        std::tuple<std::string, std::string, std::string> times = std::make_tuple(__DATE__, __TIME__, __TIMESTAMP__);
        return times;
    }

}

