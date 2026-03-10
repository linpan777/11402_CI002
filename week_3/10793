#include<iostream>
using namespace std;

int Case{0};
int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int T, first, last;
	cin >> T;
	
	while (T--)
	{
		cin >> first >> last;
		int sum{ 0 };

		if (first % 2 == 0)
			first++;
		for (int i{ first }; i <= last; i += 2)
			sum += i;

		cout << "Case " << ++Case << ": " << sum << '\n';
	}
}

