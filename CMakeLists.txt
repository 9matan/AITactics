cmake_minimum_required(VERSION 3.6)
project(AITactics)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

function(SourceGroupWithPaths SOURCE_GROUP_FILES)
    foreach(_source IN ITEMS ${SOURCE_GROUP_FILES})
        get_filename_component(_source_path "${_source}" PATH)
        string(REPLACE "/" "\\" _source_path_msvc "${_source_path}")
        source_group("${_source_path_msvc}" FILES "${_source}")
    endforeach()
endfunction()

option(AITACTICS_EXAMPLE "Build the example project" ON)
option(AITACTICS_TEST "Build the test project" ON)

add_subdirectory(Code)

if(AITACTICS_EXAMPLE MATCHES ON)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT AITacticsExample)
endif()