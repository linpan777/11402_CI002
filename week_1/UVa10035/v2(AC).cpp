#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> addend;
vector<int> adder;

void add(int& times);

int main()
{
	long long int a, b;
	while (cin >> a >> b)
	{
		if (a < b)//固定被加數>加數
			swap(a, b);
		int times{ 0 };//以下三為初始化
		addend.clear();
		adder.clear();

		if (a == 0 && b == 0)//確認結束code的00
			break;

		/*
			將int倒著放進vector
			例：
			a = 123, b = 456
					2 1 0
			addend	1 2 3
			adder   4 5 6
		*/
		while (a != 0)
		{
			addend.push_back(a % 10);
			a /= 10;
		}
		while (b != 0)
		{
			adder.push_back(b % 10);
			b /= 10;
		}

		add(times);
		if (times == 0)
			cout << "No carry operation." << endl;
		else if (times == 1)
			cout << "1 carry operation." << endl;
		else
			cout << times << " carry operations." << endl;
	}
}

void add(int& times)
{
	for (int i{ 0 }; i < adder.size(); i++)
		addend[i] += adder[i];

	for (int i{ 0 }; i < addend.size() - 1; i++)
		if (addend[i] >= 10)
		{
			addend[i] -= 10;
			addend[i + 1]++;
			times++;
		}

	if (addend[addend.size() - 1] >= 10)
	{
		addend[addend.size() - 1] -= 10;
		addend.push_back(1);
		times++;
	}
}