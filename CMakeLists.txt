cmake_minimum_required(VERSION 3.18.4)

project (toadofsky)

find_package(fmt CONFIG REQUIRED)

add_compile_options(-std=c++20)
add_compile_options(-Wall -Wextra -Wpedantic -Werror)

add_subdirectory(src)
