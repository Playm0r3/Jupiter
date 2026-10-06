add_library(jupiter_engine STATIC

        sources/Astre.cpp
        sources/Scene.cpp
        sources/components/Transform.cpp
        sources/components/Component.cpp
        sources/utils/ComponentUtilities.cpp
        sources/Window.cpp
)

target_include_directories(jupiter_engine PUBLIC include)

target_link_libraries(jupiter_engine PUBLIC jmath soleil SDL3::SDL3)

option(ENGINE_BUILD_TEST "Build les tests du jupiter engine" ON)
if(ENGINE_BUILD_TEST)
    add_subdirectory(test)
endif()