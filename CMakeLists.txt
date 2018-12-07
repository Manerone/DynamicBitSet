cmake_minimum_required(VERSION 3.6)
project(dynamic-bitset)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
add_executable(dynamic_bitset ${SOURCE_FILES})