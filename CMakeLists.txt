cmake_minimum_required(VERSION 3.8)
project(Structure_Types)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES library.c library.h)
add_library(Structure_Types ${SOURCE_FILES})