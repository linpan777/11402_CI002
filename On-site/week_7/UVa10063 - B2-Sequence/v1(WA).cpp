#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int N, Case{ 1 };
	while (cin >> N)
	{
		long long int sequence[101] = { 0 };
		long long int answer[100000] = { 0 };
		bool B2 = true;

		for (int i{ 0 }; i < N; i++)
			cin >> sequence[i];

		for (int i{ 0 }; i < N; i++)
			for (int j{ i }; j < N; j++)
				if (answer[sequence[i] + sequence[j]] > 0)
					B2 = false;
				else
				{
					answer[sequence[i] + sequence[j]]++;
					continue;
				}

		if (B2)
			cout << "Case #" << Case++ << ": It is a B2-Sequence.\n";
		else
			cout << "Case #" << Case++ << ": It is not a B2-Sequence.\n";
	}
}
//set