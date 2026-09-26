
set(DX sources/directx)
set(IN sources/interface)

add_library(soleil STATIC
        ${DX}/DirectXInstance.cpp
        ${DX}/DirectXDevice.cpp
        ${DX}/DirectXCommandQueue.cpp
        ${DX}/DirectXSwapchain.cpp
        ${DX}/DirectXDescriptorHeap.cpp
        ${DX}/DirectXCpuDescriptorHandle.cpp
        ${DX}/DirectXResource.cpp
        ${DX}/DirectXCommandallocator.cpp
        ${DX}/DirectXCompiler.cpp
        ${DX}/DirectXShader.cpp
        ${DX}/DirectXPipelineState.cpp


        ${IN}/CommandListType.cpp
        ${IN}/HeapDescriptorType.cpp
        ${IN}/LogicOp.cpp
        ${IN}/InputFormat.cpp
        ${IN}/FillMode.cpp
        ${IN}/CullMode.cpp
        ${IN}/BlendOp.cpp
        ${IN}/Blend.cpp
)

message("[Soleil] Build pour : ${TARGET_ARCHITECTURE}")

target_include_directories(soleil PUBLIC include PRIVATE ${CMAKE_SOURCE_DIR}/externs/dxc/lib/${TARGET_ARCHITECTURE}/dxcompiler.lib)

target_link_libraries(soleil
    PRIVATE
        d3d12.lib
        dxgi.lib
        d3dcompiler.lib
        ${CMAKE_SOURCE_DIR}/externs/dxc/lib/${TARGET_ARCHITECTURE}/dxcompiler.lib
)

option(RENDERING_BUILD_SANDBOX "Build rendering sandbox executable" ON)
if(RENDERING_BUILD_SANDBOX)
    add_subdirectory(sandbox)
endif()