add_library(model_a SHARED)
add_library(model_b SHARED)
add_library(model_c SHARED)

target_include_directories(model_a PUBLIC "../broker")
target_include_directories(model_b PUBLIC "../broker")
target_include_directories(model_c PUBLIC "../broker")

target_sources(model_a PUBLIC model_a.cpp)
target_sources(model_b PUBLIC model_b.cpp)
target_sources(model_c PUBLIC model_c.cpp)
