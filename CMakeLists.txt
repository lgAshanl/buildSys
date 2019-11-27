cmake_minimum_required(VERSION 2.8)

project(cp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(main ${CMAKE_CURRENT_SOURCE_DIR}/B/main.cpp)

add_subdirectory(A)


add_custom_command (OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/C/index.h
                    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/C/preparing.py
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/C)

add_custom_target(
    gen_index ALL
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/C/index.h
)

add_dependencies(main gen_index)

target_link_libraries(main file)

find_package(Doxygen)
 if(DOXYGEN_FOUND)
    set(DOXYGEN_INPUT ${CMAKE_SOURCE_DIR})
    add_custom_target(
        doc
        COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/doc/doxygen.conf
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doc)
    add_dependencies(main doc)
 else(DOXYGEN_FOUND)
    message(STATUS "WARNING: Doxygen not found - Reference manual will not be created")
endif(DOXYGEN_FOUND)
