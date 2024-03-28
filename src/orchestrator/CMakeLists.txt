add_library(orchestrator SHARED)

target_sources(orchestrator PUBLIC orchestrator.cpp)

target_include_directories(orchestrator PUBLIC "../models")

target_link_libraries(orchestrator PUBLIC pthread)

