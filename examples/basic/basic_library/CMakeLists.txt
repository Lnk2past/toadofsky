add_library(basic_library STATIC)

target_include_directories(basic_library PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory(models)
add_subdirectory(modules)

target_link_libraries(basic_library PUBLIC fmt::fmt toadofsky)
