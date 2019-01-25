set(EXAMPLE_SOURCE_FILES ./AITacticsExample/main.cpp)

add_executable(AITacticsExample ${EXAMPLE_SOURCE_FILES})
target_link_libraries(AITacticsExample AITacticsEngine)