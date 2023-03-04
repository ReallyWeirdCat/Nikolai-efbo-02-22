#include "eq2.h"
#include <iostream>

int main()
{
	using namespace std;
	eq2 mas[2];
	double a, b, c, x;
	for (int i = 0; i < 2; i++)
	{
		cout << "Enter the 3 coefficients of the equation #" << i + 1 << " (ax^2 + bx + c = 0): ";
		cin >> a >> b >> c;
		mas[i] = eq2(a, b, c);

		cout << "Solutions:" << endl;
		double res = mas[i].find_X();
		if (res != 0) {
			cout << res << endl;
		}

		cout << endl << "Enter the value of X to be used to solve the polynomial (ax^2 + bx + c = ?): ";
		cin >> x;

		cout << "Result: " << mas[i].find_Y(x) << endl;
	}

	cout << endl << "..." << endl << endl << "We will try to sum the coefficients from the previous two equations." << endl;
	eq2 new_one = mas[0] + mas[1];

	cout << "Solving the obtained equation:" << endl;

	double res = new_one.find_X();
	if (res != 0) {
		cout << res << endl;
	}

	system("pause");
}