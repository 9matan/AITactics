cmake_minimum_required(VERSION 3.6)
project(AITactics)

option(AITACTICS_EXAMPLE "Build the example project" ON)

add_subdirectory(Code)

if(AITACTICS_EXAMPLE MATCHES ON)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT AITacticsExample)
endif()