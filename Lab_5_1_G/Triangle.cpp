#include "Triangle.h"

Triangle::Triangle()
	: Triad()
{}

Triangle::Triangle(double A, double B, double C) throw(logic_error)
{
	if (!(A + B > C && B + C > A && A + C > B))
		throw logic_error("Condition is not met");

	SetA(A); SetB(B); SetC(C);
}

Triangle::Triangle(const Triangle& v)
	: Triad(v)
{}

Triangle& Triangle::operator ++() throw(out_of_range)
{
	this->SetA(this->GetA() + 1);
	if (GetA() > 10 || GetB() > 10 || GetC() > 10)
		throw out_of_range("Side is bigger than 10");
	return *this;
}

Triangle& Triangle::operator --() throw(MyDerivedException)
{
	this->SetB(this->GetB() - 1);
	if (GetB() == 0)
		throw new MyDerivedException();
	return *this;
}

Triangle Triangle::operator ++(int) throw (MyException)
{
	Triangle a(*this);
	this->SetA(this->GetA() + 1);
	if (GetA() > 10 || GetB() > 10 || GetC() > 10)
		throw MyException("Side is bigger than 10");
	return a;
}

Triangle Triangle::operator --(int) throw(MyDerivedException)
{
	Triangle a(*this);
	this->SetB(this->GetB() - 1);
	if (GetB() == 0)
		throw MyDerivedException();
	return a;
}

double Triangle::Sum()
{
	return GetA() + GetB() + GetC();
}

double Triangle::Square() const
{
	double a = GetA();
	double b = GetB();
	double c = GetC();
	double S = 0;
	double p = (a + b + c) / 2;
	S = sqrt(p * (p - a) * (p - b) * (p - c));
	return S;
}

void Triangle::Angle(double& A, double& B, double& C) const
{
	const double PI = atan(1) * 4;
	double a = GetA();
	double b = GetB();
	double c = GetC();

	double S = Square();
	double sinA = (S * 2) / (a * b);
	double x1 = asin(sinA);
	A = (x1 * 180) / PI;

	double sinB = (sinA * b) / c;
	double x2 = asin(sinB);
	B = (x2 * 180) / PI;

	C = 180 - (A + B);
}