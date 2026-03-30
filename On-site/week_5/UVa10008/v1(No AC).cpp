#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Alpha {
	char alpha = ' ';
	int count{ 0 };
};

bool cmp(Alpha a, Alpha b);

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	cin.ignore();
	string setences;
	
	Alpha Char[26];

	while (T--)
	{
		getline(cin, setences);

		for (char c : setences)
		{
			if (islower(c))
				c = toupper(c);  // ❌ 錯誤：只修改區域變數 c，不會影響實際字元的處理
			else if (c > '0' && c < '9' || c == '\n')  // ❌ 錯誤：邏輯有誤，應用 !isupper(c)
				continue;
			Char[c - 65].alpha = c;
			Char[c - 65].count++;
		}
	}
	sort(Char, Char + 25, cmp);  // ❌ 錯誤：應為 Char + 26，範圍不完整
	for (int i{ 0 }; i < 26; i++)
		if (Char[i].count == 0)
			break;
		else
			cout << Char[i].alpha << ' ' << Char[i].count << '\n';
}

bool cmp(Alpha a, Alpha b)
{
	if (a.count > b.count)
		return true;  // ❌ 錯誤：沒有處理計數相同時的字母順序
	return false;
}