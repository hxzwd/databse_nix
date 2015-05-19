cmake_minimum_required(VERSION 2.8)

set(HEADERS misc.h menu.h)
set(SRC main.cpp dump.cpp fnct.cpp menu.cpp)

project(database_linux_version)
IF(UNIX)
	set(CMAKE_CXX_COMPILER "g++-4.9")
	add_definitions("-std=c++11")
ELSE()
	
ENDIF()

add_executable(main ${HEADERS} ${SRC})
