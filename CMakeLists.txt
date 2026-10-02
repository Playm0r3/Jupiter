cmake_minimum_required(VERSION 3.20)
project(Jupiter VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build unit tests" OFF)

if(CMAKE_SYSTEM_PROCESSOR STREQUAL "AMD64")
    set(TARGET_ARCHITECTURE "x64")
else()
    set(TARGET_ARCHITECTURE "arm64")
endif()

include_directories(externs/dxc/inc)

#add_subdirectory(libs/physics)
#add_subdirectory(libs/scripting)
add_subdirectory(libs/rendering)
#add_subdirectory(libs/engine)
#add_subdirectory(editor)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()