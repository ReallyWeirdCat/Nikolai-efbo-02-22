#include "rational.h"

//Is this allowed here? Maybe not
//
//int NOD(int x, int y)
//{
//	if (y == 0) {return x;}
//	return NOD(y, x % y);
//}

rational::rational(int a1, int b1)
{
	if (b1 == 0)
	{
		throw 0;
	}

	//since i was too afraid to put a
	//reccursion function up there, I
	//decided to just use a while loop
	int x=a1, y=b1;
	while (y != 0)
	{
		int temp = x;
		x = y;
		y = temp % y;
	}
	int nod = x;

	a1 %= b1;
	a = a1/nod;
	b = b1/nod;
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