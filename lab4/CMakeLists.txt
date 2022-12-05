cmake_minimum_required(VERSION 2.9 FATAL_ERROR)

project (lab4 LANGUAGES CXX)

add_library(Link
    Link.cpp
    Link.h
)

add_executable(main
    main.cpp
)

add_executable(pal
    palindrome.cpp
)

add_executable(pal2
    palindrome_array.cpp
)

add_executable(pal3
    palindrome_pointers.cpp
)

target_link_libraries(main
    Link
)