cmake_minimum_required(VERSION 3.10)
project(mi-proyecto-cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(mi-proyecto-cpp src/main.cpp src/other_classes.cpp)