add_library(toadofsky STATIC)

target_include_directories(toadofsky PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory(broker)
add_subdirectory(modules)
add_subdirectory(orchestrators)

target_link_libraries(toadofsky PUBLIC fmt::fmt)