//
// Created by Warren on 27/09/2026.
//

#ifndef JUPITER_TEXTURELAYOUT_H
#define JUPITER_TEXTURELAYOUT_H

#include <d3d12.h>

namespace jupiter::rendering
{

    enum TextureLayout
    {
        WM_TEXTURE_LAYOUT_UNKNOWN,
        WM_TEXTURE_LAYOUT_ROW_MAJOR,
        WM_TEXTURE_LAYOUT_64KB_UNDEFINED_SWIZZLE,
        WM_TEXTURE_LAYOUT_64KB_STANDARD_SWIZZLE
    };

    namespace utils
    {
        D3D12_TEXTURE_LAYOUT getTextureLayoutFromTextureLayout(const TextureLayout& layout);
    }

}

#endif //JUPITER_TEXTURELAYOUT_H
