#include "AComplex.h"
#include "TComplex.h"
#include <iostream>

int main()
{
    AComplex a(1, 2), b(2,3);
    TComplex c(5, PI / 2);
    a *= b;
    c *= c;
    c += c;
    c -= c;
    a += a;
    b += b;
    std::cout << "Hello World!\n";
}