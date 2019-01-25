set(AITACTICS_ENGINE_TARGET AITacticsEngine)

function(SourceGroupWithPaths SOURCE_GROUP_FILES)
    foreach(_source IN ITEMS ${SOURCE_GROUP_FILES})
        get_filename_component(_source_path "${_source}" PATH)
        string(REPLACE "/" "\\" _source_path_msvc "${_source_path}")
        source_group("${_source_path_msvc}" FILES "${_source}")
    endforeach()
endfunction()

file(
    GLOB_RECURSE SOURCE_FILES_BOOST_DI 
    LIST_DIRECTORIES false
    RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
    "${BOOST_DI_INCLUDE}/*.c*"
    "${BOOST_DI_INCLUDE}/*.h*"
)

file(
    GLOB_RECURSE SOURCE_FILES_CRCPP 
    LIST_DIRECTORIES false
    RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CRCPP_INCLUDE}/*.c*"
    "${CRCPP_INCLUDE}/*.h*"
)

file(
    GLOB_RECURSE SOURCE_FILES
    LIST_DIRECTORIES false
    RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
    "Source/*.c*"
    "Source/*.h*"
)

SourceGroupWithPaths("${SOURCE_FILES_BOOST_DI}")
SourceGroupWithPaths("${SOURCE_FILES}")
SourceGroupWithPaths("${SOURCE_FILES_CRCPP}")

include_directories(
    ./Source
    ./Source/Implementation
    ${BOOST_DI_INCLUDE}
    ${CRCPP_INCLUDE}
    )

add_library(${AITACTICS_ENGINE_TARGET} STATIC 
    ${SOURCE_FILES} 
    ${SOURCE_FILES_BOOST_DI} 
    ${SOURCE_FILES_CRCPP}
    )
    
set_target_properties(${AITACTICS_ENGINE_TARGET} PROPERTIES LINKER_LANGUAGE CXX)

if(ATOMIC_AITACTICS_SUBMODULES MATCHES ON)
# Copy to Artifacts
    add_custom_command( TARGET ${AITACTICS_ENGINE_TARGET} POST_BUILD
                    COMMAND "${CMAKE_COMMAND}"
                    ARGS -E make_directory \"${ATOMIC_SOURCE_DIR}/Artifacts/${AITACTICS_ENGINE_TARGET}\"
                    COMMAND "${CMAKE_COMMAND}"
                    ARGS -E copy_if_different \"$<TARGET_FILE:${AITACTICS_ENGINE_TARGET}>\" \"${ATOMIC_SOURCE_DIR}/Artifacts/${AITACTICS_ENGINE_TARGET}\"
                    COMMENT "Copying ${AITACTICS_ENGINE_TARGET} to Build Artifacts" )
endif()