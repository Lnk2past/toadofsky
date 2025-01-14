add_executable(compose compose.cpp)

target_include_directories(compose PUBLIC "${CMAKE_SOURCE_DIR}/include" "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(compose PUBLIC toadofsky fmt::fmt nlohmann_json::nlohmann_json)