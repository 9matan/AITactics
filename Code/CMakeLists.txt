set(THIRDPARTY_PATH ${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty)

if(NOT DEFINED BOOST_DI_INCLUDE)
    set(BOOST_DI_INCLUDE ${THIRDPARTY_PATH}/di-cpp14/include)
endif()

if(NOT DEFINED CRCPP_INCLUDE)
    set(CRCPP_INCLUDE ${THIRDPARTY_PATH}/CRCpp/inc)
endif()

set(AITACTICS_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory(AITacticsEngine)

if(AITACTICS_EXAMPLE MATCHES ON)
    add_subdirectory(AITacticsExample)
endif()

if(AITACTICS_TEST MATCHES ON)
    enable_testing()

    set(BUILD_GMOCK ON)
    
    add_subdirectory(${THIRDPARTY_PATH}/googletest-master)
    add_subdirectory(Test_AITacticsEngine)
endif()