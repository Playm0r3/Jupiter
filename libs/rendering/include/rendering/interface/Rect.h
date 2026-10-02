//
// Created by Warren on 30/09/2026.
//

#ifndef JUPITER_RECT_H
#define JUPITER_RECT_H

namespace jupiter::rendering
{
    struct Rect
    {
        long left, top, right, bottom = 0;
    };

    struct Scissor : public Rect
    {

    };
}

#endif //JUPITER_RECT_H
