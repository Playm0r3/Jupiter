
add_library(jmath STATIC
        sources/vectors/Vector.cpp
)

target_include_directories(jmath PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

option(MATH_BUILD_TEST "Build les tests de math" ON)
if(MATH_BUILD_TEST)
    add_subdirectory(test)
endif()