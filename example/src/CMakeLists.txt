cmake_minimum_required(VERSION 2.8)

project(example_console_app)

set(SOURCE_MAIN main.c)

include_directories(../../include)

add_executable(example_console_app ${SOURCE_MAIN})

add_subdirectory(../../src ../../build)

target_link_libraries(example_console_app quadratic_equation)