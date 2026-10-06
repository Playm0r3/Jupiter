//
// Created by Warren on 04/10/2026.
//

#ifndef JUPITER_JEXCEPTION_H
#define JUPITER_JEXCEPTION_H

#include <exception>

namespace jupiter::engine
{

    class JException : public std::exception
    {
    public:

        JException(const char* msg) : std::exception(msg) {}
    };

}

#endif //JUPITER_JEXCEPTION_H
