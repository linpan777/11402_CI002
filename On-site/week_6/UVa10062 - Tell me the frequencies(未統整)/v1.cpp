#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Characters
{
	int ACSII{ 0 };
	int count{ 0 };
};

bool mycmp(Characters a, Characters b);

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	string setences;
	while (getline(cin, setences))
	{
		Characters character[96];
		for (int i{ 0 }; i < setences.size(); i++)
		{
			character[setences[i] - 32].ACSII = setences[i];
			character[setences[i] - 32].count++;
		}

		sort(character, character + 96, mycmp);
		for (int i{ 0 }; i < 96; i++)
		{
			if (character[i].count != 0)
			{
				cout << character[i].ACSII << ' ' << character[i].count << '\n';
			}
		}
		cout << '\n';
	}
}

bool mycmp(Characters a, Characters b)
{
	if (a.count != b.count)
		return a.count < b.count;
	else
		return a.ACSII > b.ACSII;
}