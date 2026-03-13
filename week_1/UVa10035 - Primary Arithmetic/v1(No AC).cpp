#include <iostream>
#include <vector>
using namespace std;

void add(int& times, vector<int> addend, vector<int> adder);

int main()
{
	long long int a, b, c;
	vector<int> addend;
	vector<int> adder;
	while (cin >> a >> b)
	{
		int times{ 0 };
		addend.clear();
		adder.clear();
		if (a == 0 && b == 0)
			break;

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

        //我不知道我TM這裡在寫甚麼，我到底當時在想啥？
		c = a + b;
		for (int i{ 0 }; i > addend.size(); i++)
		{
			if (c % 10 >= addend[i])
				continue;
			else
			{
				add(times, addend, adder);
				break;
			}
		}
		
		if (times == 0)
			cout << "No carry operation." << endl;
		else
			cout << times << " carry operations." << endl;
	}
}

void add(int &times, vector<int> addend, vector<int> adder)
{
	for (int i = addend.size() - 1; i >= 0; i--)
		addend[i] += adder[i];

	for(int i{0}; i < addend.size() - 1; i++)
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