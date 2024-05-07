cmake_minimum_required(VERSION 2.8)

project(testing_quadratic_equation)

set(SOURCE_MAIN tests_interface.c tests_quadratic_equation.c tests_main.c)

include_directories(../../include)

add_executable(testing_quadratic_equation ${SOURCE_MAIN})

add_subdirectory(../../src ../../build)

target_link_libraries(testing_quadratic_equation quadratic_equation)