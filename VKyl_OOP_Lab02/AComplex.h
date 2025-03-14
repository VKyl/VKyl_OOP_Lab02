#pragma once
class TComplex;
class AComplex
{
private:
	double _re, _im;
public:
	AComplex(double re, double im) : _re(re), _im(im) {}
	AComplex(const AComplex& c) = default;
	AComplex(AComplex&& c) = default;
	AComplex(const TComplex&& c);

	~AComplex() = default;

	double& re() { return _re; }
	double re() const { return _re; }

	double& im() { return _im; }
	double im() const { return _im; }

	AComplex& operator=(AComplex z);
	AComplex& operator=(TComplex z);

	AComplex& operator+=(AComplex z);
	AComplex& operator+=(TComplex z);
	AComplex& operator-=(AComplex z);
	AComplex& operator-=(TComplex z);

	static  const double getAngle(const AComplex&& z);
	static const double getLength(const AComplex&& z);
};

AComplex& operator+(AComplex z1, AComplex z2);
AComplex& operator+(AComplex z1, TComplex z2);
AComplex& operator-(AComplex z1, AComplex z2);
AComplex& operator-(AComplex z1, TComplex z2);
