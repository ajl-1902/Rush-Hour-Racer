cmake_minimum_required(VERSION 3.6)

project(Rush-Hour-Racer)

set(EXECUTABLE_NAME "${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 20)

include_directories("${PROJECT_SOURCE_DIR}/Project")

file(GLOB SOURCES
    "${PROJECT_SOURCE_DIR}/Project/*.h"
    "${PROJECT_SOURCE_DIR}/Project/*.cpp"
    )

add_executable(${EXECUTABLE_NAME} ${SOURCES})

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${EXECUTABLE_NAME})