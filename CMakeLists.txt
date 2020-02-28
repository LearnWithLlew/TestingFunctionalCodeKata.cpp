cmake_minimum_required(VERSION 3.8)
project(TestingFunctionalCodeKata)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/CMake/")
include(CodeCoverage)
append_coverage_compiler_flags()

set(CMAKE_CXX_STANDARD 17)
include_directories(lib)

add_subdirectory(code)
add_subdirectory(tests)


