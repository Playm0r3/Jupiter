
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
        ${DX}/DirectXCommandList.cpp
        ${DX}/DirectXFence.cpp
        ${DX}/DirectXRootSignature.cpp

        ${IN}/CommandListType.cpp
        ${IN}/HeapDescriptorType.cpp
        ${IN}/LogicOp.cpp
        ${IN}/InputFormat.cpp
        ${IN}/FillMode.cpp
        ${IN}/CullMode.cpp
        ${IN}/BlendOp.cpp
        ${IN}/Blend.cpp
        ${IN}/HeapType.cpp
        ${IN}/ResourceBarrierFlags.cpp
        ${IN}/ResourceBarrierType.cpp
        ${IN}/ResourceDimension.cpp
        ${IN}/ResourceState.cpp
        ${IN}/TextureLayout.cpp
        ${IN}/InputFormat.cpp
        ${IN}/Resource.cpp
        ${IN}/PrimitiveTopology.cpp
        ${IN}/MeshLoader.cpp

        sources/InterfaceAllocator.cpp
)

message("[Soleil] Build pour : ${TARGET_ARCHITECTURE}")

set(FBX_SDK_DIR "C:/Program Files/Autodesk/FBX/FBX SDK/2020.3.11")

target_include_directories(soleil PUBLIC
        include
        "${FBX_SDK_DIR}/include"
)

target_link_libraries(soleil
    PRIVATE
        d3d12.lib
        dxgi.lib
        d3dcompiler.lib
        ${CMAKE_SOURCE_DIR}/externs/dxc/lib/${TARGET_ARCHITECTURE}/dxcompiler.lib
    PUBLIC
        "C:/Program Files/Autodesk/FBX/FBX SDK/2020.3.11/lib/x64/release/libfbxsdk.lib"
)

option(RENDERING_BUILD_SANDBOX "Build rendering sandbox executable" ON)
if(RENDERING_BUILD_SANDBOX)
    add_subdirectory(sandbox)
endif()