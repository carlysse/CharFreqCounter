cmake_minimum_required(VERSION 3.19)
project(Program2_CharFreqCounter C)

set(CMAKE_C_STANDARD 99)

add_library(Program2_CharFreqCounter library.c library.h prog2.c prog2.h)