#pragma once
#include <iostream>
using std::ostream;

class TComplex;
class AComplex
{
private:
	double _re, _im;
public:
	AComplex(const double& re, const double& im) : _re(re), _im(im) {}
	AComplex(const AComplex& c) = default;
	AComplex(AComplex&& c) = default;
	AComplex(const TComplex&& c);

	~AComplex() = default;

	double& re() { return _re; }
	const double& re() const { return _re; }

	double& im() { return _im; }
	const double& im() const { return _im; }

	AComplex& operator=(AComplex z);
	AComplex& operator=(TComplex z);

	AComplex& operator+=(AComplex z);
	AComplex& operator+=(TComplex z);
	AComplex& operator-=(AComplex z);
	AComplex& operator-=(TComplex z);
};

const double arg(const AComplex& z);
const double norm(const AComplex& z);

AComplex& operator+(AComplex z1, AComplex z2);
AComplex& operator+(AComplex z1, TComplex z2);
AComplex& operator-(AComplex z1, AComplex z2);
AComplex& operator-(AComplex z1, TComplex z2);

ostream& operator<<(ostream& out, AComplex z);
