set(EXAMPLE_SOURCE_FILES ./Source/main.cpp)

add_executable(AITacticsExample ${EXAMPLE_SOURCE_FILES})
target_link_libraries(AITacticsExample AITacticsEngine)