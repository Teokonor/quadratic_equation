cmake_minimum_required(VERSION 2.8.12)

project(quadratic_equation)

include_directories(../include)

set(SOURCE_LIB quadratic_equation.c complex_number.c)

add_library(quadratic_equation STATIC ${SOURCE_LIB})

target_link_libraries(quadratic_equation m)

target_compile_options(quadratic_equation PRIVATE -Wall -Wextra)