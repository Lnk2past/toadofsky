target_include_directories(simulation_spawn PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory(models)
add_subdirectory(modules)

target_link_libraries(simulation_spawn PUBLIC fmt::fmt)
