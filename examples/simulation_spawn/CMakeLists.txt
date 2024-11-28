add_executable(simulation_spawn simulation_spawn.cpp)

add_subdirectory(components)

target_link_libraries(simulation_spawn PUBLIC fmt::fmt toadofsky)
