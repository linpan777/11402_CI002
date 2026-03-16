#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long long int a, b, c;
	long long int times{ 0 }, max{ 0 };
	while (cin >> a >> b)
	{
		if (a > b)
			swap(a, b);
		max = 0;
		for (long long int i{ a }; i <= b; i++)
		{
			c = i;
			times = 0;
			while (c != 1)
			{
				times++;
				if (c % 2 == 1 || c == 0)
					c = 3 * c + 1;
				else
					c /= 2;
			}
			if (max < times)
				max = times;
		}
		
		if (a == 0)
			max += 2;
		cout << a << " " << b << " " << max + 1 << endl;
	}
}
