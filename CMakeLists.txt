cmake_minimum_required(VERSION 3.24)
project(CalendarServer)

set(CMAKE_CXX_STANDARD 11)
include_directories(Core/Inc)

find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
find_path(CPP_HTTPLIB_INCLUDE_DIRS "httplib.h")

file(GLOB_RECURSE SOURCES "Core/*.*")

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${Python3_INCLUDE_DIRS} ${CPP_HTTPLIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${Python3_LIBRARIES})
