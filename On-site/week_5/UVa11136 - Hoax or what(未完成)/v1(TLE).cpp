#include <iostream>
#include <vector>
using namespace std;

vector <int> bill;

void findMLI(int& max, int& less, int& lessIndex, int& maxIndex);

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n, k, sub;
	while (cin >> n && n != 0)
	{
		bill.clear();
		int amount{ 0 };
		while (n--)
		{
			cin >> k;
			while(k--)
			{
				cin >> sub;
				bill.push_back(sub);
			}

			int max{ 0 }, less{ 999999 }, maxIndex, lessIndex;
			findMLI(max, less, lessIndex, maxIndex);

			amount += max - less;
			bill[maxIndex] = 0;
			bill[lessIndex] = 0;

			max = 0; less = 999999;
		}
		cout << amount << '\n';
	}
}

void findMLI(int &max, int &less, int &lessIndex, int &maxIndex)
{
	for (int i{ 0 }; i < bill.size(); i++)
	{
		less = (less == 0) ? bill[i] : less;
		if (bill[i] > max)
		{
			max = bill[i];
			maxIndex = i;
		}
		if (bill[i] < less)
		{
			less = bill[i];
			lessIndex = i;
		}
	}
}