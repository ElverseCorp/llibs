cmake_minimum_required(VERSION 3.10)
project(llibs)

set(CMAKE_C_STANDARD 11)

add_library(llibs STATIC)

# target_compile_options(llibs PRIVATE ${WINDOWS_COMPILE_FLAGS})
target_include_directories(llibs PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/cross/include
)

file(GLOB_RECURSE LLIBS_SRC "src/*.c" "cross/src/*.c" "native/${CMAKE_SYSTEM_NAME}/src/*.c")
target_sources(llibs PRIVATE ${LLIBS_SRC})