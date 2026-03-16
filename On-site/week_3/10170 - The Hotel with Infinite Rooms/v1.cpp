#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	long long int people, day;

	while (cin >> people >> day)
	{
		while (day != 0)//其實沒意義，直接改true也可以
		{
			day -= people;

			if (day <= 0)
				break;
			else
				people++;
		}
		cout << people << '\n';
	}
}

