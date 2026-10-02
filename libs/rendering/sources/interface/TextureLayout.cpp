//
// Created by Warren on 27/09/2026.
//

#include "rendering/interface/TextureLayout.h"

namespace jupiter::rendering::utils
{

    D3D12_TEXTURE_LAYOUT getTextureLayoutFromTextureLayout(const TextureLayout& layout)
    {
        switch (layout)
        {
        case WM_TEXTURE_LAYOUT_ROW_MAJOR:
            return D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
        case WM_TEXTURE_LAYOUT_64KB_UNDEFINED_SWIZZLE:
            return D3D12_TEXTURE_LAYOUT_64KB_UNDEFINED_SWIZZLE;
        case WM_TEXTURE_LAYOUT_64KB_STANDARD_SWIZZLE:
            return D3D12_TEXTURE_LAYOUT_64KB_STANDARD_SWIZZLE;
        case WM_TEXTURE_LAYOUT_UNKNOWN:
        default:
            return D3D12_TEXTURE_LAYOUT_UNKNOWN;
        }
    }

}