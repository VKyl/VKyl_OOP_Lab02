#include "TComplex.h"
#include "AComplex.h"

TComplex::TComplex(const AComplex& z)
{
    _arg = acomplex::arg(z);
    _norm = acomplex::norm(z);

}

TComplex& TComplex::operator=(const AComplex& z)
{
    _arg = acomplex::arg(z);
    _norm = acomplex::norm(z);
    return *this;
}

TComplex& TComplex::operator=(const TComplex& z)
{
    _arg = z.arg();
    _norm = z.norm();
    return *this;
}

TComplex& TComplex::operator*=(const TComplex& z)
{
    _arg += z.arg();
    _norm *= z.norm();
    return *this;
}

TComplex& TComplex::operator*=(const AComplex& z)
{
    _arg += acomplex::arg(z);
    _norm *= acomplex::norm(z);
    return *this;
}

TComplex& TComplex::operator/=(const TComplex& z)
{
    if (z.norm() <= DBL_EPSILON) throw ZERO_DIVISON_EXCEPTION;
    _arg -= z.arg();
    _norm /= z.norm();
    return *this;
}

TComplex& TComplex::operator/=(const AComplex& z)
{
    const double z2_norm = acomplex::norm(z);
    if (z2_norm <= DBL_EPSILON) throw ZERO_DIVISON_EXCEPTION;
    _arg -= acomplex::arg(z);
    _norm /= acomplex::norm(z);
    return *this;
}

const double real(const TComplex& z)
{
    return std::cos(z.arg()) * z.norm();
}

const double imaginary(const TComplex& z)
{
    return std::sin(z.arg()) * z.norm();
}
const TComplex operator*(const TComplex& z1, const TComplex& z2)
{
    return { z1.arg() + z2.arg(), z1.norm() * z2.norm() };
}

const TComplex operator*(const TComplex& z1, const AComplex& z2)
{
    return { z1.arg() + acomplex::arg(z2), z1.norm() * acomplex::norm(z2) };
}

const TComplex operator/(const TComplex& z1, const TComplex& z2)
{
    if (z2.norm() <= DBL_EPSILON) throw ZERO_DIVISON_EXCEPTION;
    return { z1.arg() - z2.arg(), z1.norm() / z2.norm() };
}

const TComplex operator/(const TComplex& z1, const AComplex& z2)
{
    const double z2_norm = acomplex::norm(z2);
    if (z2_norm <= DBL_EPSILON) throw ZERO_DIVISON_EXCEPTION;
    return {z1.arg() - acomplex::arg(z2), z1.norm() * z2_norm};
}


ostream& operator<<(ostream& out, TComplex z)
{
    out << z.norm() << "*(cos(" << z.arg() << ") + i*sin(" << z.arg() << "))";
    return out;
}
