cmake_minimum_required(VERSION 2.9 FATAL_ERROR)

project (lab3 LANGUAGES CXX)

add_library(MyVector
    MyVector.cpp
    MyVector.hpp
)

add_executable(main
    main.cpp
)

add_executable(es1_2_3
    es1_2_3_lab3.cpp
)

target_link_libraries(main
    MyVector
)