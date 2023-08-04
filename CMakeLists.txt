cmake_minimum_required(VERSION 3.25)
project(codepiler C)

set(CMAKE_C_STANDARD 11)

file(GLOB_RECURSE CODEPILER_SOURCES
        "codepiler/*.c"
        "codepiler/*.h"
        )

add_executable(codepiler ${CODEPILER_SOURCES})
