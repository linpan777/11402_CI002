#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	
	int N, Q, temp, Case{ 1 };
	while(cin >> N >> Q && N != 0 && Q != 0)
	{
		vector<int> number;
		cout << "CASE# " << Case++ << ":\n";
		for (int i{ 0 }; i < N; i++)
		{
			cin >> temp;
			number.push_back(temp);
		}
		sort(number.begin(), number.end());

		for(int i{0}; i < Q; i++)
		{
			cin >> temp;
			auto it = lower_bound(number.begin(), number.end(), temp);
			int index = it - number.begin();

			if (it < number.end() && number[index] == temp)
				cout << temp << " found at " << index + 1 << '\n';
			else
				cout << temp << " not found\n";
		}
	}
}