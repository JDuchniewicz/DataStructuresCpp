cmake_minimum_required(VERSION 3.8)
project(SLList)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp SLList.h cmake-build-debug/DLRing.h)
add_executable(SLList ${SOURCE_FILES})