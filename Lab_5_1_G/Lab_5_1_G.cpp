#include "Triangle.h"

void _unexpected_to_bad()
{
	cerr << "bad_exception" << endl;
	throw;
}

void Call_Bad() throw(bad_exception)
{
	throw bad_exception();
}

int main()
{
	cout << "Number of elements of class Triangle : " << Triangle::Count() << endl;

	try
	{
		Triangle K(5, 2, 5);

		cout << "Size of public class: " << sizeof(K) << endl;
		cout << "Number of elements of class Triangle : " << Triangle::Count() << endl;

		double A = 0.0;
		double B = 0.0;
		double C = 0.0;

		cout << "Square: " << K.Square() << endl;

		K.Angle(A, B, C);
		cout << "Angle A = " << A << endl;
		cout << "Angle B = " << B << endl;
		cout << "Angle C = " << C << endl << endl;
		try
		{
			K--;
		}
		catch (MyDerivedException a)
		{
			cerr << a.What() << endl << endl;
		}
		catch (MyDerivedException* a)
		{
			cerr << a->What() << endl << endl;
		}
	}
	catch (logic_error a)
	{
		cerr << "Exception: " << a.what() << endl;
	}

	cout << "Number of elements of class Triangle : " << Triangle::Count() << endl;

	Triangle N(10, 9, 8);

	cout << "Number of elements of class Triangle : " << Triangle::Count() << endl;

	try
	{
		N++;
	}
	catch (MyException& a)
	{
		cerr << "Exception: " << a.What() << endl;
	}
	catch (out_of_range a)
	{
		cerr << "Exception: " << a.what() << endl;
	}

	try
	{
		Call_Bad();
	}
	catch (bad_exception)
	{
		cerr << "catch (bad_exception)" << endl;
	}
}