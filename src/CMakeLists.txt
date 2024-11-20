add_library(toadofsky STATIC)

add_subdirectory(broker)
add_subdirectory(modules)
add_subdirectory(orchestrators)

target_link_libraries(toadofsky PUBLIC fmt::fmt)