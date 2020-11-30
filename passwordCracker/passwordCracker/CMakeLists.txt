cmake_minimum_required(VERSION 3.12)
project(SourceCodeEmptyMain C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(SourceCodeEmptyMain
        main.c
        PasswordChecker.c
        PasswordChecker.h
        PasswordDefinitions.h
        SolutionListOperations.c
        SolutionListOperations.h
        StructureDefinitions.h)
