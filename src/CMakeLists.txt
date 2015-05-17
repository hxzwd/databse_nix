cmake_minimum_required(VERSION 2.8)

project(database_linux_version)
set(CMAKE_CXX_COMPILER "g++-4.9")
add_definitions("-std=c++11")
add_executable(main main.cpp dump.cpp fnct.cpp menu.cpp)
