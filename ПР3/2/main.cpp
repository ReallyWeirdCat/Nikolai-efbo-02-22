#include "rational.h"

using namespace std;

int main()
{
	int N, a, b;
	cout << "Enter the amount N of the rational fractions: "; cin >> N;

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

	fracs = NULL;
	delete fracs;

	return 0;
}