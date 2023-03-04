#include <iostream>
#include <math.h>

class rational
{
private:
	int a, b;
public:
	rational(int a1, int b1);
	rational();
	void set(int a1, int b1);
	void show();

	rational operator + (rational& y);
	friend rational operator - (rational& x, rational& y);
	rational operator ++ ();

	friend bool operator == (rational& x, rational& y);
	friend bool operator > (rational& x, rational& y);
	rational& operator = (const rational& x);

};