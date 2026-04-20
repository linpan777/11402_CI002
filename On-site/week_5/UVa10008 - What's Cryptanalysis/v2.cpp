#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 定義字母結構體：儲存字元及其計數
struct Alpha {
	char alpha = ' ';      // 字母本身
	int count{ 0 };        // 出現次數
};

// 比較函式：用於排序
bool cmp(Alpha a, Alpha b);

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;       // 讀取測資數量
	cin.ignore();          // 忽略輸入緩衝區的換行符
	string setences;       // 儲存一行文字
	
	Alpha Char[26];        // 26 個字母的結構體陣列（已初始化為 0）

	while (T--)            // 處理每個測資
	{
		getline(cin, setences);  // 讀取整行文字（包括空格）

		// 遍歷字串中的每個字元
		for (char c : setences)
		{
			// 若為小寫字母，轉換為大寫
			if (islower(c))
				c = toupper(c);
			// 若不是字母，跳過
			else if (!isupper(c))
				continue;
			
			// 更新對應字母的計數（'A' 在索引 0，'Z' 在索引 25）
			Char[c - 65].alpha = c;
			Char[c - 65].count++;
		}
	}
	
	// 按照自訂規則排序：先按計數降序，再按字母升序
	sort(Char, Char + 26, cmp);
	
	// 輸出排序後的結果
	for (int i{ 0 }; i < 26; i++)
	{
		// 若計數為 0，表示後續皆無字母出現，停止輸出
		if (Char[i].count == 0)
			break;
		else
			cout << Char[i].alpha << ' ' << Char[i].count << '\n';
	}
}

// 比較函式：用於排序
// 返回 true 表示 a 應排在 b 之前
bool cmp(Alpha a, Alpha b)
{
	if (a.count != b.count)
		return a.count > b.count;  // 計數多的排前面（降序）
    else
	    return a.alpha < b.alpha;   // 計數相同時，字母小的排前面（升序）
}