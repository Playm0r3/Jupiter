add_library(soleil STATIC
        sources/directx/DirectXInstance.cpp
        sources/directx/DirectXDevice.cpp
        sources/directx/DirectXCommandQueue.cpp
)

target_include_directories(soleil PUBLIC include)

target_link_libraries(soleil
    PRIVATE
        d3d12.lib
        dxgi.lib
        d3dcompiler.lib
)

option(RENDERING_BUILD_SANDBOX "Build rendering sandbox executable" ON)
if(RENDERING_BUILD_SANDBOX)
    add_subdirectory(sandbox)
endif()