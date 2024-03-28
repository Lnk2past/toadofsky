cmake_minimum_required(VERSION 3.18.4)

project (toadofsky)

add_compile_definitions(FMT_HEADER_ONLY)
add_compile_options(-std=c++20)
add_compile_options(-Wall -Wextra -Wpedantic -Werror)

add_subdirectory(src)
