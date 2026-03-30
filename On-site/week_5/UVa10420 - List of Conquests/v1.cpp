#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	map<string, int> count;
	while (T--)
	{
		string country, girl;
		cin >> country;
		getline(cin, girl);
		
		count[country]++;
	}
	for (auto it : count)
		cout << it.first << ' ' << it.second << '\n';


}