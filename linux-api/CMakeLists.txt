cmake_minimum_required(VERSION 2.8)

project(linux-api)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c99)
set(SOURCE_FILES ename.h uxlib.h uxlib.c tlpi_hdr.h error_functions.h error_functions.c main.c)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} )
