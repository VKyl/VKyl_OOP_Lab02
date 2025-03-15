#include "AComplex.h"
#include "TComplex.h"

//AComplex& AComplex::operator=(const TComplex& z)
//{
//    _re = tcomplex::real(z);
//    _im = tcomplex::imaginary(z);
//    return *this;
//}

namespace acomplex
{
    const double arg(const AComplex& z)
    {
        return std::atan2(z.im(), z.re());
    }

    const double norm(const AComplex& z)
    {
        return sqrt(z.re() * z.re() + z.im() * z.im());
    }
}

AComplex& operator+=(AComplex& z1, const AComplex& z2)
{
    z1.re() += z2.re();
    z1.im() += z2.im();
    return z1;
}
//
//AComplex& operator+=(AComplex& z1, const TComplex& z2)
//{
//    // Addition assignment implementation goes here
//    return z1;
//}

AComplex& operator-=(AComplex& z1, const AComplex& z2)
{
    // Subtraction assignment implementation goes here
    return z1;
}

//AComplex& operator-=(AComplex& z1, const TComplex& z2)
//{
//    // Subtraction assignment implementation goes here
//    return z1;
//}

const AComplex operator+(const AComplex& z1, const AComplex& z2)
{
    // Addition implementation goes here
    return AComplex(); // Placeholder return
}

//const AComplex operator+(const AComplex& z1, const TComplex& z2)
//{
//    // Addition implementation goes here
//    return AComplex(); // Placeholder return
//}

const AComplex operator-(const AComplex& z1, const AComplex& z2)
{
    // Subtraction implementation goes here
    return AComplex(); // Placeholder return
}

//const AComplex operator-(const AComplex& z1, const TComplex& z2)
//{
//    // Subtraction implementation goes here
//    return AComplex(); // Placeholder return
//}

std::ostream& operator<<(std::ostream& out, AComplex z)
{
    // Output stream implementation goes here
    return out;
}
