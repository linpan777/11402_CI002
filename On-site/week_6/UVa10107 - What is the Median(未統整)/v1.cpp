#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	vector<int> numberList;
	int number{ 0 }, size{ 0 };
	while (cin >> number)
	{
		numberList.push_back(number);
		size = numberList.size();
		sort(numberList.begin(), numberList.end());
		if (size % 2 == 0)
			cout << ((numberList[size / 2 - 1]) + numberList[size / 2]) / 2 << '\n';
		else
			cout << numberList[size / 2] << '\n';
	}
}