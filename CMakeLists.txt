cmake_minimum_required(VERSION 3.6)
project(TP03)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Summit.cpp Summit.h Graph.cpp Graph.h Header.h Edges.cpp Edges.h)
add_executable(TP03 ${SOURCE_FILES})
