#include<iostream>
#include<string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	string sentence;
	bool check = 0;

	while (getline(cin, sentence))
	{
		for (int i{ 0 }; i < sentence.size(); i++)
		{
			if (sentence[i] == '"')//只要遇到"就進判斷，利用bool來確認是第一個還是第二個
			{
				if (check == 0)
				{
					cout << "``";
					check = 1;
				}
				else
				{
					cout << "''";
					check = 0;
				}
				continue;
			}
			cout << sentence[i];//沒有遇到就正常的cout sentence裡的字
		}
		cout << '\n';
	}
}
