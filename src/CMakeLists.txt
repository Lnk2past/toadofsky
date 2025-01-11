add_library(toadofsky STATIC)

target_include_directories(toadofsky PUBLIC "${CMAKE_SOURCE_DIR}/include" "${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory(orchestrator)

target_link_libraries(toadofsky PUBLIC fmt::fmt)