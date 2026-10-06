//
// Created by Warren on 02/10/2026.
//

#include <iostream>

#include "jmath/vectors/Vector.h"
#include "jmath/utils.h"

using namespace jupiter::math;

int main()
{
    std::cout << "[Jupiter - Math] Hello Math Test\n" << std::endl;

    std::cout << "[ang(v2) methode]" << std::endl;

    Vector a{0.0, 1.0};
    Vector b{1.0, 0.0};

    double angle = ang(a, b);
    double angld = 180 / PI * angle;

    std::cout << "a : " << a.toString() << std::endl;
    std::cout << "b : " << b.toString() << std::endl;
    std::cout << "r : " << std::to_string(angle) << std::endl;
    std::cout << "d : " << std::to_string(angld) << std::endl;

    std::cout << "[ang(v3) methode]" << std::endl;

    Vector3 a3{1.0, 0.0, 0.0};
    Vector3 b3{1.0, 1.0, 0.0};

    double angle3 = ang(a3, b3);
    double angld3 = 180 / PI * angle3;

    std::cout << "a : " << a3.toString() << std::endl;
    std::cout << "b : " << b3.toString() << std::endl;
    std::cout << "r : " << std::to_string(angle3) << std::endl;
    std::cout << "d : " << std::to_string(angld3) << std::endl;

    return 0;
}