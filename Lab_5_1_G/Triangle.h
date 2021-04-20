
#pragma once
#include "Triad.h"

class Triangle : public Triad
{
public:
	Triangle();
	Triangle(double a, double b, double c) throw(logic_error);
	Triangle(const Triangle& v);

	Triangle& operator ++ () throw(out_of_range);
	Triangle& operator -- () throw(MyDerivedException);
	Triangle operator ++ (int) throw(MyException);
	Triangle operator -- (int) throw(MyDerivedException);

	double Sum();
	double Square() const;
	void Angle(double& A, double& B, double& C) const;
};