cmake_minimum_required(VERSION 3.27)
project(Assignment9_FractionOverloadedOperators)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assignment9_FractionOverloadedOperators
        RationalNumber.cpp
        RationalNumber.h
        app.cpp)
