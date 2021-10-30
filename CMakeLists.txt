cmake_minimum_required(VERSION 3.20)
project(evol)

set(CMAKE_CXX_STANDARD 17)

add_executable(evol main.cpp graph.h graph.cpp)
