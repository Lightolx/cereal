cmake_minimum_required(VERSION 3.14)
project(binary)

set(CMAKE_CXX_STANDARD 14)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
#add_executable(binary temp.cpp)
add_executable(binary main.cpp)