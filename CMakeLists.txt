project(AITactics)

file(
    GLOB_RECURSE SOURCE_FILES_BOOST_DI 
    LIST_DIRECTORIES false
    RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
    "${BOOST_DI_INCLUDE}/*.c*"
    "${BOOST_DI_INCLUDE}/*.h*"
)

foreach(_source IN ITEMS ${SOURCE_FILES_BOOST_DI})
    get_filename_component(_source_path "${_source}" PATH)
    string(REPLACE "/" "\\" _source_path_msvc "${_source_path}")
    source_group("${_source_path_msvc}" FILES "${_source}")
endforeach()

file(
    GLOB_RECURSE SOURCE_FILES 
    LIST_DIRECTORIES false
    RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
    "Source/*.c*"
    "Source/*.h*"
)

foreach(_source IN ITEMS ${SOURCE_FILES})
    get_filename_component(_source_path "${_source}" PATH)
    string(REPLACE "/" "\\" _source_path_msvc "${_source_path}")
    source_group("${_source_path_msvc}" FILES "${_source}")
endforeach()

include_directories(
    Source
    Source/Implementation
    ${BOOST_DI_INCLUDE}
)

add_library(AITactics STATIC ${SOURCE_FILES} ${SOURCE_FILES_BOOST_DI})
set_target_properties(AITactics PROPERTIES LINKER_LANGUAGE CXX)

#ATOMIC BEGIN

# Copy to Artifacts
add_custom_command( TARGET AITactics POST_BUILD
                    COMMAND "${CMAKE_COMMAND}"
                    ARGS -E make_directory \"${ATOMIC_SOURCE_DIR}/Artifacts/AITactics\"
                    COMMAND "${CMAKE_COMMAND}"
                    ARGS -E copy_if_different \"$<TARGET_FILE:AITactics>\" \"${ATOMIC_SOURCE_DIR}/Artifacts/AITactics\"
                    COMMENT "Copying AITactics to Build Artifacts" )

if (WIN32)

  # pre-Windows 8 can't count on D3DCompiler_47.dll being on system
  add_custom_command (TARGET AITactics POST_BUILD
  COMMAND ${CMAKE_COMMAND}
  ARGS -E copy_if_different \"${D3DCOMPILER_47_DLL}\" \"$<TARGET_FILE_DIR:AITactics>/D3DCompiler_47.dll\"
  COMMAND ${CMAKE_COMMAND}
  ARGS -E copy_if_different \"${D3DCOMPILER_47_DLL}\" \"${ATOMIC_SOURCE_DIR}/Artifacts/AITactics/D3DCompiler_47.dll\" )

endif(WIN32)

#ATOMIC END