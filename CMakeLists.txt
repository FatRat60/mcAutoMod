cmake_minimum_required(VERSION 3.10)

# set proj name
project(MC_Mod_Manager)

# specifiy c++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# add pbind11
#add_subdirectory(pybind11)


# glob to get all common source files
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/common/*.cpp")

# get all headers 
file(GLOB_RECURSE HEADERS "${CMAKE_SOURCE_DIR}/src/include/*.h")

# OS specific 
if (NOT WIN32)

    add_compile_options("-Wall")
    add_compile_options("-pedantic")
    add_compile_options("-Werror=return-type")

    if (APPLE)
        file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/mac/*.cpp")
    else()
        file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/linux/*.cpp")
    endif()
else()
    # Windows
    file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/win/*.cpp")
endif()

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} ${HEADERS})
