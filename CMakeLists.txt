cmake_minimum_required(VERSION 3.19.6)

set(This Intpart)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(GoogleTest)

set(Headers
Intpart.hpp
)

set(Sources
Intpart.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)