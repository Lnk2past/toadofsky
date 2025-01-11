cmake_minimum_required(VERSION 3.18.4)

project(example_nbody)

include("${CMAKE_CURRENT_SOURCE_DIR}/../../build/Release/toadofskyTargets.cmake")

find_package(fmt CONFIG REQUIRED)

add_executable(simulation_spawn simulation_spawn.cpp)

add_subdirectory(components)

target_link_libraries(simulation_spawn PUBLIC fmt::fmt toadofsky)
