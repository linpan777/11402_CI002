#include <iostream>
using namespace std;

void parity(int number);
int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int number;
	while (cin >> number && number != 0)
	{
		cout << "The parity of ";

		int count{ 0 };
		parity(number);

		while (number != 0)
		{
			if (number % 2 == 1)
				count++;

			number /= 2;
		}

		cout << " is " << count << " (mod 2).\n";
	}
}

void parity(int number)
{
	if (number == 0)
		return;

	parity(number / 2);
	cout << number % 2;
}