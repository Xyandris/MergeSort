cmake_minimum_required(VERSION 3.20...3.31)
project(MergeSortProjekt LANGUAGES CXX)

# Program i testy korzystaja z tego samego standardu C++.
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(mergesort main.cpp)
