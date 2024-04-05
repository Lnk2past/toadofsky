add_library(orchestrator SHARED)

target_sources(orchestrator PUBLIC orchestrator.cpp )

target_link_libraries(orchestrator fmt::fmt pthread module_a module_b module_c)

