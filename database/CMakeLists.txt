cmake_minimum_required(VERSION 3.7)
project(database)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES MichaelLendinoDatabase.c)
add_executable(database ${SOURCE_FILES})