#include "rational.h"

using namespace std;

int main()
{
	int N, a, b;
	cout << "Enter the amount N of the rational fractions: "; cin >> N;

	if (N == 0)
	{
		return 0;
	}

	rational* fracs = new rational[N];

	for (int i = 0; i < N; i++)
	{
		cout << "Fraction #" << i + 1 << " (a b): ";
		cin >> a >> b;
		try
		{
			fracs[i] = rational(a, b);
		}
		catch (int err)
		{
			cout << "Error. Make sure that b is not zero." << endl;
			i--;
		}
	}

	for (int i = 0; i < N; i++)
	{
		fracs[i].show();
	}

	rational X = fracs[0];
	rational Y;
	if (N < 2)
	{
		//If the user is too lazy to enter a second fraction,
		//then I need to do it myself
		Y = rational(1, 2);
	}
	else
	{
		Y = fracs[1];
	}

	cout << endl << "....." << endl << "X = "; X.show();
	cout << "Y = "; Y.show(); cout << endl;

	cout << "1) X+Y: "; (X + Y).show();
	cout << "2) X-Y: "; (X - Y).show();
	cout << "6) Z=X; 3) ++Z: "; rational Z = X; ++Z; Z.show();

	cout << "4) X==Y: " << (X == Y) << endl;
	cout << "5) X>Y: " << (X > Y) << endl;

	fracs = NULL;
	delete[] fracs;



	return 0;
}