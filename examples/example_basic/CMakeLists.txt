cmake_minimum_required(VERSION 3.18.4)

project(example_basic)

include("${CMAKE_CURRENT_SOURCE_DIR}/../../build/${CMAKE_BUILD_TYPE}/toadofskyTargets.cmake")

find_package(fmt CONFIG REQUIRED)

add_subdirectory(basic_library)

add_executable(basic_orchestrator basic_orchestrator.cpp)
target_link_libraries(basic_orchestrator PUBLIC fmt::fmt toadofsky basic_library)

add_executable(basic_pool_orchestrator basic_pool_orchestrator.cpp)
target_link_libraries(basic_pool_orchestrator PUBLIC fmt::fmt toadofsky basic_library)

