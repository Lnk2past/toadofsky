cmake_minimum_required(VERSION 3.18.4)

project (toadofsky)

set(CMAKE_VERBOSE_MAKEFILE ON)

find_package(fmt CONFIG REQUIRED)

add_compile_options(-std=c++20)
add_compile_options(-Wall -Wextra -Wpedantic -Werror)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)

export(TARGETS toadofsky FILE "${CMAKE_BINARY_DIR}/toadofskyTargets.cmake")
