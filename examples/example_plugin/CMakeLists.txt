cmake_minimum_required(VERSION 3.18.4)

project(example_plugins)

include("${CMAKE_CURRENT_SOURCE_DIR}/../../build/Release/toadofskyTargets.cmake")

find_package(fmt CONFIG REQUIRED)

add_compile_options(-std=c++20)
add_compile_options(-Wall -Wextra -Wpedantic -Werror)

add_library(test_plugin SHARED test_plugin.cpp)
add_library(test_plugin_publisher SHARED test_plugin_pub.cpp)

target_link_libraries(test_plugin PUBLIC fmt::fmt toadofsky)
target_link_libraries(test_plugin_publisher PUBLIC fmt::fmt toadofsky)
