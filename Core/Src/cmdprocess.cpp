//
// Created by 秦子若 on 2023/1/26.
//

#include "cmdprocess.h"

#include <QTimer>
#include <iostream>
#include <QCommandLineParser>
#include <QCoreApplication>

CommandLineProcessor::CommandLineProcessor(QCoreApplication *parent) : QObject(parent) {
    // Process the command line arguments
    QCommandLineParser parser;
    parser.setApplicationDescription("Calendar Server");  // 描述可执行程序的属性
    parser.addHelpOption();                           // 添加帮助命令
    parser.addVersionOption();                         // 添加版本选择命令

    parser.process(*parent);
}

void CommandLineProcessor::Help() {
    std::cout << "Calendar Server Help" << std::endl;
}

void CommandLineProcessor::Wait5Seconds() {
    std::cout << "waitting 5 seconds..." << std::endl;//5秒后可以正常输入命令
    QTimer::singleShot(5000, this, SLOT(beginNextLoop()));
}

void CommandLineProcessor::startup() {
    std::cout << "Calendar Server version " << PROJECT_VERSION_NUMBER << std::endl;
    BeginNextLoop();
}

void CommandLineProcessor::WaitForInput() {
    std::string command;

    std::cin >> command;

    DispatchCommand(QString(command.c_str()));
}

void CommandLineProcessor::DispatchCommand(const QString &command) {
    if (command == "quit") {
        finished();
        return;
    } else if (command == "help") {
        Help();
        BeginNextLoop();
    } else if (command == "wait") {
        Wait5Seconds();
    }
}

void CommandLineProcessor::BeginNextLoop() {
    QTimer::singleShot(0, this, SLOT(beginNextLoop()));
}

void CommandLineProcessor::beginNextLoop() {
    WaitForInput();
}