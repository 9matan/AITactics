file(
    GLOB_RECURSE TEST_ENGINE_SOURCE 
    LIST_DIRECTORIES false
    RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
    "./Tests/*.c*"
    "./Tests/*.h*"
)

SourceGroupWithPaths("${TEST_ENGINE_SOURCE}")

include_directories(
    ${gtest_SOURCE_DIR}/include 
    ${AITACTICS_ENGINE_INCLUDE}
    )

add_executable(Test_AITacticsEngine ${TEST_ENGINE_SOURCE})

target_link_libraries(Test_AITacticsEngine gtest AITacticsEngine)

add_test(NAME Test_AITacticsEngine COMMAND Test_AITacticsEngine)