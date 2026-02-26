# UVa 100 - The 3n+1 Problem

## Problem Description
Brief description of the problen -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=36)

## Learning Objectives
1. Learn about 3n+1 conjecture
2. Practice i/o in C++
3. loop logic

## Preliminary thinking
### variable reference
| 變數 | 意義 |
| :--- | :--- |
| `a` | input number 1 |
| `b` | input number 2 |
| `c` | core loop variable |
| `times` | core loop to caculate cycle length |
| `max` | every time to store max cycle lenth | 
### Algorithm logic
```text
1. input a, b
2. for loop(a -> b)
3.      while loop(c != 1)
4.          ++times
5.          (the core algorithm of 3n+1)
6.      if(max < times)
7.          max = times
8. output
```

## Challenges
1. `a` must smaller than `b`.
2. core loop is wrong, the condition of variable `c` shoud be check after `times++`.
3. 0 is not in the cindition.

## New code struct
```C++
<details>

<summary> click to open </summary>

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long long int a, b, c;
	long long int times{ 0 }, max{ 0 };
	while (cin >> a >> b)
	{
		cout << a << " " << b;//在互換之前先輸出滿足題目要求
		if (a > b)//a固定要 < b
			swap(a, b);
		max = 0;//每一次max都要作重製，否則會使用到上一組測資的資料

		for (long long int i{ a }; i <= b; i++)
		{
			c = i;//a b i作為for loop的基準，不可做更動，因此使用新變數來作為core code的變數基準
			times = 0;//每一次的time都需要作重製，不然每一次會逐漸累加
			while (true)
			{
				times++;
				if (c == 1)
					break;

				if (c % 2 == 1)
					c = 3 * c + 1;
				else
					c /= 2;
			}
			if (max < times)
				max = times;
		}

		cout << " " << max << endl;
	}
}
</detail>

```
[source code](v2(AC).cpp)

## Complexity Analysis
- Time complexity：*O(N \* C)
- Space complexity： *O(1)

## Note
1. 真的不行就看中文版。
2. **不要緊張！！！不要緊張！！！不要緊張！！！**
> 💡 緊張就會亂思路！
3. 寫完發現有問題不要東拼西湊，重看邏輯哪裡有問題！