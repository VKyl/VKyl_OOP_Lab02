#include "AComplex.h"
#include "TComplex.h"
#include <iostream>

int main()
{
    AComplex a(1, 2);
    static_cast<TComplex>(a);

    std::cout << "Hello World!\n";
}