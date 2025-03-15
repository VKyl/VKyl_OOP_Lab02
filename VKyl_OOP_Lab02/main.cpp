#include "AComplex.h"
#include "TComplex.h"
#include <iostream>

int main()
{
    AComplex z1(2, 3), z2(0, 3);
    TComplex z3(2, PI / 2);

    std::cout << "AComplex: z1 = " << z1 << ", z2 = " << z2 << std::endl;
    std::cout << "TComplex: z3 = " << z3 << std::endl;

    std::cout << "z1 + z2 = " << (z1 + z2) << std::endl;
    std::cout << "z1 - z2 = " << (z1 - z2) << std::endl;
    std::cout << "z1 * z2 = " << (z1 * z2) << std::endl;
    std::cout << "z1 / z2 = " << (z1 / z2) << std::endl;

    std::cout << "z1 + z3 = " << (z1 + z3) << std::endl;
    std::cout << "z1 * z3 = " << (z1 * z3) << std::endl;
    std::cout << "z1 / z3 = " << (z1 / z3) << std::endl;

    std::cout << "z3 + z2 = " << (z3 + z2) << std::endl;
    std::cout << "z3 * z2 = " << (z3 * z2) << std::endl;
    std::cout << "z3 / z2 = " << (z3 / z2) << std::endl;

    double d1 = 5.0;
    std::cout << "d1 + z1 = " << (d1 + z1) << std::endl;
    std::cout << "d1 * z1 = " << static_cast<AComplex>(d1 * z1) << std::endl;

    return 0;
}
