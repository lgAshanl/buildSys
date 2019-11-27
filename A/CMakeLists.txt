cmake_minimum_required(VERSION 2.8)

set(SOURCE_LIB file.cpp)

add_library(file STATIC ${SOURCE_LIB})

add_definitions(-DOS_TOOLS_LIN=1)