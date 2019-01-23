project(AITactics)

function(SourceGroupWithPaths SOURCE_GROUP_FILES)
    foreach(_source IN ITEMS ${SOURCE_GROUP_FILES})
        get_filename_component(_source_path "${_source}" PATH)
        string(REPLACE "/" "\\" _source_path_msvc "${_source_path}")
        source_group("${_source_path_msvc}" FILES "${_source}")
    endforeach()
endfunction()

if(NOT DEFINED BOOST_DI_INCLUDE)
    set(BOOST_DI_INCLUDE Submodules/BoostDI/include)
endif()

file(
    GLOB_RECURSE SOURCE_FILES_BOOST_DI 
    LIST_DIRECTORIES false
    RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
    "${BOOST_DI_INCLUDE}/*.c*"
    "${BOOST_DI_INCLUDE}/*.h*"
)

SourceGroupWithPaths("${SOURCE_FILES_BOOST_DI}")

file(
    GLOB_RECURSE SOURCE_FILES 
    LIST_DIRECTORIES false
    RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
    "Source/*.c*"
    "Source/*.h*"
)

SourceGroupWithPaths("${SOURCE_FILES}")

include_directories(
    Source
    Source/Implementation
    ${BOOST_DI_INCLUDE}
)

add_library(AITactics STATIC ${SOURCE_FILES} ${SOURCE_FILES_BOOST_DI})
set_target_properties(AITactics PROPERTIES LINKER_LANGUAGE CXX)

if(ATOMIC_AITACTICS_SUBMODULES)
# Copy to Artifacts
    add_custom_command( TARGET AITactics POST_BUILD
                    COMMAND "${CMAKE_COMMAND}"
                    ARGS -E make_directory \"${ATOMIC_SOURCE_DIR}/Artifacts/AITactics\"
                    COMMAND "${CMAKE_COMMAND}"
                    ARGS -E copy_if_different \"$<TARGET_FILE:AITactics>\" \"${ATOMIC_SOURCE_DIR}/Artifacts/AITactics\"
                    COMMENT "Copying AITactics to Build Artifacts" )
endif()