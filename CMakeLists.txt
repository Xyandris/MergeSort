cmake_minimum_required(VERSION 3.20...3.31)
project(MergeSortProjekt LANGUAGES CXX)

# Program i testy korzystaja z tego samego standardu C++.
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(mergesort main.cpp)


# CTest pozwala uruchamiac wszystkie testy jednym poleceniem.
include(CTest)
if(BUILD_TESTING)
    include(FetchContent)

    # Ta opcja ustawia zgodna biblioteke uruchomieniowa w Visual Studio.
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_Declare(
        googletest
        URL https://codeload.github.com/google/googletest/zip/refs/tags/v1.14.0
        URL_HASH SHA256=1f357c27ca988c3f7c6b4bf68a9395005ac6761f034046e9dde0896e3aba00e4
    )
    FetchContent_MakeAvailable(googletest)

    add_executable(testy_merge_sort tests/test_merge_sort.cpp)
    target_include_directories(testy_merge_sort PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(testy_merge_sort PRIVATE GTest::gtest_main)

    include(GoogleTest)
    gtest_discover_tests(testy_merge_sort)
endif()
