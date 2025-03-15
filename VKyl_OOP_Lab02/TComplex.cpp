#include "TComplex.h"
#include "AComplex.h"


TComplex::TComplex(const AComplex& z): _arg(acomplex::arg(z)), _norm(acomplex::norm(z)) {}

const double& TComplex::arg(const double&& val)
{
    _arg = val;
    normalize();
    return _arg;
}

const double& TComplex::norm(const double&& val)
{
    _norm = val;
    normalize();
    return _norm;
}

void TComplex::normalize()
{
    if (_norm < 0)
    {
        _norm *= -1;
        _arg += PI;
    }

    if (_arg != 0) _arg = fmod(_arg, PERIOD);
}

const double tcomplex::real(const TComplex& z)
{
    return std::cos(z.arg()) * z.norm();
}

const double tcomplex::imaginary(const TComplex& z)
{
    return std::sin(z.arg()) * z.norm();
}


TComplex& operator/=(TComplex& z1, const TComplex& z2)
{
    if (z2.norm() == 0) throw ZERO_DIVISON_EXCEPTION;
    z1.arg(z1.arg() - z2.arg());
    z1.norm(z1.norm() + z2.norm());
    return z1;
}

TComplex& operator*=(TComplex& z1, const TComplex& z2) 
{
    z1.arg(z1.arg() + z2.arg());
    z1.norm(z1.norm() * z2.norm());
    return z1;
}

const TComplex operator*(const TComplex& z1, const TComplex& z2)
{
    return { z1.norm() * z2.norm(), z1.arg() + z2.arg() };
}

const TComplex operator/(const TComplex& z1, const TComplex& z2)
{
    if (z2.norm() == 0) throw ZERO_DIVISON_EXCEPTION;
    return { z1.norm() / z2.norm(), z1.arg() - z2.arg()};
}

ostream& operator<<(ostream& out, TComplex z)
{
    out << z.norm() << "*(cos(" << z.arg() << ") + i*sin(" << z.arg() << "))";
    return out;
}
