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