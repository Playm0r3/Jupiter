
add_library(math STATIC
        sources/vectors/Vector.cpp
)

target_include_directories(math PUBLIC include)

option(MATH_BUILD_TEST "Build les tests de math" ON)
if(MATH_BUILD_TEST)
    add_subdirectory(test)
endif()