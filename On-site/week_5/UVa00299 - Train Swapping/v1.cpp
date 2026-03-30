#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while (T--)
	{
		vector<int> train;
		int how_many_train{ 0 }, temp{ 0 };

		cin >> how_many_train;
		for (int i{ 0 }; i < how_many_train; i++)
		{
			cin >> temp;
			train.push_back(temp);
		}

		int count{ 0 };
		for(int i{0}; i < how_many_train; i++)
			for (int j{ 0 }; j < how_many_train - 1 - i; j++)
			{
				if (train[j] > train[j + 1])
				{
					swap(train[j], train[j + 1]);
					count++;
				}
			}

		cout << "Optimal train swapping takes " << count << " swaps.\n";
	}
}