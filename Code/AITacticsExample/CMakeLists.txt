set(EXAMPLE_SOURCE_FILES ./main.cpp)

add_executable(AITacticsExample ${EXAMPLE_SOURCE_FILES})
target_link_libraries(AITacticsExample AITacticsEngine)
include_directories(${AITACTICS_INCLUDE})