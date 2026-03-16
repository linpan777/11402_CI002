#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long long int a, b, c;
	long long int times{ 0 }, max{ 0 };
	while (cin >> a >> b)
	{
		cout << a << " " << b;//在互換之前先輸出滿足題目要求
		if (a > b)//a固定要 < b
			swap(a, b);
		max = 0;//每一次max都要作重製，否則會使用到上一組測資的資料

		for (long long int i{ a }; i <= b; i++)
		{
			c = i;//a b i作為for loop的基準，不可做更動，因此使用新變數來作為core code的變數基準
			times = 0;//每一次的time都需要作重製，不然每一次會逐漸累加
			while (true)
			{
				times++;
				if (c == 1)
					break;

				if (c % 2 == 1)
					c = 3 * c + 1;
				else
					c /= 2;
			}
			if (max < times)
				max = times;
		}

		cout << " " << max << endl;
	}
}
