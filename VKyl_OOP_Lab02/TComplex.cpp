#include "TComplex.h"
#include <iostream>
using std::ostream;

class TComplex
{
private:
	double _arg, _norm;

public:
		TComplex(const double& arg, const double& norm): _arg(arg), _norm(norm) {}
};