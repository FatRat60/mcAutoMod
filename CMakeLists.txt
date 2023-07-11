cmake_minimum_required(VERSION 3.10)

# set proj name
project(MC_Mod_Manager)

# specifiy c++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# add pbind11
add_subdirectory("${CMAKE_SOURCE_DIR}/extern/pybind11")

if (pybind11_FOUND)
    message(STATUS "${pybind11_INCLUDE_DIR}\n${CMAKE_SOURCE_DIR}")
endif()

include_directories("${pybind11_INCLUDE_DIR}")

# glob to get all common source files
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/common/*.cpp")

# get all headers 
set(HEADERS_DIR "${CMAKE_SOURCE_DIR}/include/mcmodmanager")
include_directories("${HEADERS_DIR}")
file(GLOB_RECURSE HEADERS "${HEADERS_DIR}/*.h")

# OS specific 
if (NOT WIN32)

    add_compile_options("-Wall")
    add_compile_options("-pedantic")
    add_compile_options("-Werror=return-type")

    if (APPLE)
        list(APPEND SOURCES "${CMAKE_SOURCE_DIR}/src/mac/methods_mac.cpp")
    else()
        list(APPEND SOURCES "${CMAKE_SOURCE_DIR}/src/linux/methods_linux.cpp")
    endif()
else()
    # Windows
    list(APPEND SOURCES "${CMAKE_SOURCE_DIR}/src/win/methods_win.cpp")
endif()

message(STATUS ${SOURCES})

pybind11_add_module(mcmod ${SOURCES} ${HEADERS})
