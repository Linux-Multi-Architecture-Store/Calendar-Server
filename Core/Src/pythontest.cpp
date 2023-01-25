#include <iostream>
#include <cstdio>
#include <clocale>
#include "pythontest.h"
#include <Python.h>

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