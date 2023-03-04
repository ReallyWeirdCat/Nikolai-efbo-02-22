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