option(AITACTICS_EXAMPLE ON)

set(THIRDPARTY_PATH ${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty)

if(NOT DEFINED BOOST_DI_INCLUDE)
    set(BOOST_DI_INCLUDE ${THIRDPARTY_PATH}/di-cpp14/include)
endif()

if(NOT DEFINED CRCPP_INCLUDE)
    set(CRCPP_INCLUDE ${THIRDPARTY_PATH}/CRCpp/inc)
endif()

add_subdirectory(Engine)

if(AITACTICS_EXAMPLE)
    add_subdirectory(Example)
endif()