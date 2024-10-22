cmake_minimum_required(VERSION 3.10)
project(llibs)

set(CMAKE_C_STANDARD 11)

add_library(llibs STATIC)

target_include_directories(llibs PUBLIC
    "cross/include/"
)

target_sources(llibs PRIVATE
    "cross/src/c/mem.c"
)