cmake_minimum_required(VERSION 3.27)
project(Security_System)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Security_System
        system.cpp
        system.h)
