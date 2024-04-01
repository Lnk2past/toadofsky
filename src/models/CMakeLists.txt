add_library(model_a SHARED)
add_library(model_b SHARED)
add_library(model_c SHARED)

target_sources(model_a PUBLIC model_a.cpp)
target_sources(model_b PUBLIC model_b.cpp)
target_sources(model_c PUBLIC model_c.cpp)

target_link_libraries(model_a PUBLIC fmt::fmt)
target_link_libraries(model_b PUBLIC fmt::fmt)
target_link_libraries(model_c PUBLIC fmt::fmt)
