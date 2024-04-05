add_library(module_a SHARED)
add_library(module_b SHARED)
add_library(module_c SHARED)

target_sources(module_a PUBLIC module_a.cpp)
target_sources(module_b PUBLIC module_b.cpp)
target_sources(module_c PUBLIC module_c.cpp)

target_link_libraries(module_a PUBLIC fmt::fmt model_a)
target_link_libraries(module_b PUBLIC fmt::fmt model_b)
target_link_libraries(module_c PUBLIC fmt::fmt model_c)
