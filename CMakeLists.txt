cmake_minimum_required(VERSION 3.10)
project(c-unplugg)

set(CMAKE_C_STANDARD 11)

include_directories(
    $(CMAKE_SOURCE_DIR)
    $(CMAKE_SOURCE_DIR)/src
    $(CMAKE_SOURCE_DIR)/include
)
set(SOURCES

src/main.c
src/function.c
include/function.h
)

add_executable(run ${SOURCES})