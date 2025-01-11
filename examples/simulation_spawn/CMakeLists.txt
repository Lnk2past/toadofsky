cmake_minimum_required(VERSION 3.18.4)

project(example_nbody)

find_package(fmt CONFIG REQUIRED)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../../src ${CMAKE_CURRENT_BINARY_DIR}/src)

add_executable(simulation_spawn simulation_spawn.cpp)

add_subdirectory(components)

target_link_libraries(simulation_spawn PUBLIC fmt::fmt toadofsky)
