cmake_minimum_required(VERSION 3.8)
project(TestingFunctionalCodeKataTests)
set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES
        main.cpp
        LegacyTest.cpp
        Test.cpp
        )
add_executable(TestingFunctionalCodeKataTests ${SOURCE_FILES} )