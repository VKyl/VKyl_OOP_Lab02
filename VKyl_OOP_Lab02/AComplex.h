#pragma once
class AComplex
{
private: 
	double _re, _im;
public:
	AComplex(double re, double im): _re(re), _im(im) {}
	AComplex(const AComplex& c) = default;
	AComplex(AComplex&& c) = default;
	~AComplex() = default;

	double& re() { return _re; }
	double re() const{ return _re; }

	double& im() { return _im; }
	double im() const { return _im; }
};

