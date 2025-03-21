#pragma once
#include <iostream>
using std::ostream;

class TComplex;

class AComplex
{
private:
	double _re, _im;
public:
	AComplex(const double& re = 0, const double& im = 0) : _re(re), _im(im) {}
	AComplex(const AComplex& c) = default;
	AComplex(AComplex&& c) = default;
	AComplex(const TComplex& c);

	~AComplex() = default;

	double& re() { return _re; }
	const double& re() const { return _re; }

	double& im() { return _im; }
	const double& im() const { return _im; }

	AComplex& operator=(const AComplex& z) = default;
	AComplex& operator=(AComplex&& z) = default;
};

namespace acomplex
{
	const double arg(const AComplex& z);
	const double norm(const AComplex& z);
}

const AComplex operator+(const AComplex& z1, const AComplex& z2);
const AComplex operator-(const AComplex& z1, const AComplex& z2);

AComplex& operator+=(AComplex& z1, const AComplex& z2);
AComplex& operator-=(AComplex& z1, const AComplex& z2);

bool operator==(const AComplex & z1, const AComplex & z2);
ostream& operator<<(ostream& out, AComplex z);
