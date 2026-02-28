#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int first, second, answer;

	while (cin >> first >> second)
	{
		if (first == 0 && second == 0)
			break;
		int times{ 0 };
        bool carry = false;

		if (first < second)
			swap(first, second);

		while (first != 0)
		{
			answer = (carry) ? first % 10 + second % 10 + 1 : first % 10 + second % 10;
			if (answer >= 10)
			{
				times++;
				carry = true;
			}
			else
				carry = false;

			first /= 10;
			second /= 10;
		}

		if (times == 0)
			cout << "No carry operation.\n";
		else if (times == 1)
			cout << "1 carry operation.\n";
		else
			cout << times << " carry operations.\n";
	}
}