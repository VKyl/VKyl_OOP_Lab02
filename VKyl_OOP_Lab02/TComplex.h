#pragma once
#include <iostream>
#include <numbers>
using std::ostream;

const std::overflow_error ZERO_DIVISON_EXCEPTION = std::overflow_error("The dark magic of dividing by zero is forbidden!");
const double PI = std::numbers::pi_v<double>;
const double PERIOD = 2 * PI;

class AComplex;

class TComplex
{
private:
	double _arg, _norm;

public:
	TComplex(const double& norm = 0, const double& arg = 0) : _arg(arg), _norm(norm) {}
	TComplex(const TComplex& z) = default;
	TComplex(TComplex& z) = default;
	TComplex(const AComplex& z);
	~TComplex() = default;

	const double& arg() { return _arg; }
	const double& arg() const { return _arg; }
	const double& arg(const double&& val);

	const double& norm() { return _norm; }
	const double& norm() const { return _norm; }
	const double& norm(const double&& val);

	TComplex& operator=(const TComplex& z) = default;
	TComplex& operator=(TComplex&& z) = default;
	TComplex& operator=(const AComplex& z);

private:
	void normalize();

};

namespace tcomplex
{
	const double real(const TComplex& z);
	const double imaginary(const TComplex& z);
}

TComplex& operator*=(const TComplex& z1, const TComplex& z2);
TComplex& operator*=(const TComplex& z1, const AComplex& z2);
TComplex& operator/=(TComplex& z1, const TComplex& z2);
TComplex& operator/=(TComplex& z1, const AComplex& z2);

const TComplex operator*(const TComplex& z1, const TComplex& z2);
const TComplex operator*(const TComplex& z1, const AComplex& z2);
const TComplex operator/(const TComplex& z1, const TComplex& z2);
const TComplex operator/(const TComplex& z1, const AComplex& z2);

ostream& operator<<(ostream& out, TComplex z);
