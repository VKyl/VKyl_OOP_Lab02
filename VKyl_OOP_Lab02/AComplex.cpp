#include "AComplex.h"
#include "TComplex.h"

AComplex::AComplex(const TComplex& c) : _re(tcomplex::real(c)), _im(tcomplex::imaginary(c)) {}

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

AComplex& operator-=(AComplex& z1, const AComplex& z2)
{
    z1.re() -= z2.re();
    z1.im() -= z2.im();
    return z1;
}

const AComplex operator+(const AComplex& z1, const AComplex& z2)
{
    std::cout << z2 << std::endl;
    return { z1.re() + z2.re(), z1.im() + z2.im() };
}

const AComplex operator-(const AComplex& z1, const AComplex& z2)
{
    return { z1.re() - z2.re(), z1.im() - z2.im() };
}

bool operator==(const AComplex& z1, const AComplex& z2)
{
    return fabs(z1.re() - z2.re() + z1.im() - z2.im()) <= DBL_EPSILON;
}


std::ostream& operator<<(std::ostream& out, AComplex z)
{
    char sign = (z.im() >= 0) ? '+' : '/0';
    out << z.re() << sign << z.im() << "*i";
    return out;
}
