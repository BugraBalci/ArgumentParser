cmake_minimum_required(VERSION 3.5)

project(ArgPar LANGUAGES C)

add_executable(ArgPar main.c lib.h argumentparser.c ArgName.c freeStringArray.c)
