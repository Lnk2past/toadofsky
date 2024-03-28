add_subdirectory(broker)
add_subdirectory(models)
add_subdirectory(orchestrator)

add_executable(toadofsky main.cpp)

target_link_libraries(toadofsky PUBLIC broker model_a model_b orchestrator)