file(
    GLOB_RECURSE TEST_ENGINE_SOURCE 
    LIST_DIRECTORIES false
    RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
    "./*.c*"
    "./*.h*"
)

SourceGroupWithPaths("${TEST_ENGINE_SOURCE}")

include_directories(
    ${gtest_SOURCE_DIR}/include 
    ${gmock_SOURCE_DIR}/include
    ${AITACTICS_INCLUDE}
    )

add_executable(AITacticsEngine_Test ${TEST_ENGINE_SOURCE})

target_link_libraries(AITacticsEngine_Test gtest gmock AITacticsEngine)

add_test(NAME Test_AITacticsEngine COMMAND Test_AITacticsEngine)