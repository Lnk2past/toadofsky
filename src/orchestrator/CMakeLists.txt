add_library(orchestrator SHARED)

target_sources(orchestrator PUBLIC orchestrator.cpp)

target_include_directories(orchestrator PUBLIC "../models" "../broker")

target_link_libraries(orchestrator PUBLIC pthread model_a model_b model_c)

