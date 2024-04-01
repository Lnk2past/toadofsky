add_library(orchestrator SHARED)

target_sources(orchestrator PUBLIC orchestrator.cpp)

target_link_libraries(orchestrator fmt::fmt pthread model_a model_b model_c)

