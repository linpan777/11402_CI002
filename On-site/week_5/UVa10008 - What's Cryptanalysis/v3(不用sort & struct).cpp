#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	cin.ignore();
	string setences;

	// 改進 1：用簡單的整數陣列替代結構體，直接存計數
	int Char[26] = { 0 };
	int Max{ 0 };  // 改進 2：記錄最大出現次數，方便逆向遍歷
	
	while (T--)
	{
		getline(cin, setences);

		for (char c : setences)
		{
			// 改進 3：統一轉換為大寫，避免小寫判斷的複雜度
			if (islower(c))
				c = toupper(c);
			// 改進 4：使用 !isupper(c) 簡化非字母的判斷邏輯
			else if (!isupper(c))
				continue;
			
			Char[c - 65]++;

			// 改進 5：邊計數邊追蹤最大值，避免 sort() 的開銷
			if (Max < Char[c - 65])
				Max = Char[c - 65];
		}
	}
	
	// 改進 6：按計數從大到小遍歷（逆向），不用 sort
	// 同計數時自動按字母順序輸出（因為 j 循環是升序的）
	for (int i{ Max }; i > 0; i--)
		for (int j{ 0 }; j < 26; j++)
			if (Char[j] == i)
				cout << static_cast<char>(j + 65) << ' ' << i << '\n';
}