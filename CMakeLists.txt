cmake_minimum_required(VERSION 3.15)
project(itertools)

set(CMAKE_CXX_STANDARD 14)

add_executable(itertools Demo.cpp filterfalse.hpp accumulate.hpp range.hpp)