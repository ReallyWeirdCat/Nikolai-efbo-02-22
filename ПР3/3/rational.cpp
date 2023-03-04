#include "rational.h"

rational::rational(int a1, int b1)
{
	if (b1 == 0)
	{
		throw 0;
	};
	if (a1>=b1)
	{
		a1 %= b1;
	};
	if (a1 != 0 && b1 % a1 == 0)
	{
		b1 /= a1;
		a1 = 1;
	}
	a = a1;
	b = b1;
}

rational::rational()
{
	//Creates a "null" object.
	//This exists so we could
	//actually use a dynamic array (:
}

void rational::set(int a1, int b1)
{
	*this = rational(a1, b1);
}

void rational::show()
{
	std::cout << a << "/" << b << std::endl;
}

rational rational::operator + (rational& y)
{
	int a1 = this->a; 
	int b1 = this->b;
	int a2 = y.a;
	int b2 = y.b;
	return rational(a1 * b2 + a2 * b1, b1 * b2);
}

rational operator - (rational& x, rational& y)
{
	int a1 = x.a;
	int b1 = x.b;
	int a2 = y.a;
	int b2 = y.b;

	return rational(a1 * b2 - a2 * b1, b1 * b2);
}

bool operator == (rational& x, rational& y)
{
	double a1 = x.a;
	double b1 = x.b;
	double a2 = y.a;
	double b2 = y.b;

	return a1 / b1 == a2 / b2;
}

bool operator > (rational& x, rational& y)
{
	double a1 = x.a;
	double b1 = x.b;
	double a2 = y.a;
	double b2 = y.b;

	return a1 / b1 > a2 / b2;
}

rational rational::operator ++ ()
{
	*this = rational(a + 1, b);
	return *this;
}

rational& rational::operator = (const rational& x)
{
	//...zochem
	a = x.a;
	b = x.b;
	return *this;
}