# UVa 10035 - Primary Arithmetic

## Problem Description
Brief description of the problen -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=976)

> [!Note]
>## Learning Objectives
>1. Digit Extraction: Learning to use modulo ``% 10`` to isolate the last digit and division ``(/ 10)`` to shift to the next digit, processing the number from right to left.
>2. Learning how to use a variable to store the "carry" status from the previous column's addition and pass it forward into the next loop iteration.

## Thinking
### variable reference
| variable | meaning |
| :--- | :--- |
| `a` | input number 1 |
| `b` | input number 2 |
| `times` | Carry number |
| `addend` | vector to store fist number |
| `adder` | vector to store second number |

### Algorithm logic
```text
main：
1. input a, b
2. if(a < b) swap(a, b)
3. if(a=0 & b=0) break;
4. while(a != 0)
5.      Push a into the vector in reverse.
6. b same as a
7. add(time)
8. ouput
```
```text
add(&time)：
1. for(0 -> adder.size)
2.      addend += adder
3. for(0 -> addend.size - 1)//避免碰到未知vector
4.      if(addend >= 10) -=10; addend[i+1]++; time++;
5. if(addend[addend.size - 1] >= 10) same as 4.
```

## Challenges
1. performing addition in the add function, the <ruby>boundary<rt>*邊界*</rt></ruby> condition must be based on adder; otherwise, an **out-of-bounds** exception will occur, limited is occur because of it.

## New code struct
<details>
<summary> <head>click to open<head> </summary>

```C++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> addend;
vector<int> adder;

void add(int& times);

int main()
{
	long long int a, b;
	while (cin >> a >> b)
	{
		if (a < b)//固定被加數>加數
			swap(a, b);
		int times{ 0 };//以下三為初始化
		addend.clear();
		adder.clear();

		if (a == 0 && b == 0)//確認結束code的00
			break;

		/*
			將int倒著放進vector
			例：
			a = 123, b = 456
					2 1 0
			addend	1 2 3
			adder   4 5 6
		*/
		while (a != 0)
		{
			addend.push_back(a % 10);
			a /= 10;
		}
		while (b != 0)
		{
			adder.push_back(b % 10);
			b /= 10;
		}

		add(times);
		if (times == 0)
			cout << "No carry operation." << endl;
		else if (times == 1)
			cout << "1 carry operation." << endl;
		else
			cout << times << " carry operations." << endl;
	}
}

void add(int& times)
{
	for (int i{ 0 }; i < adder.size(); i++)
		addend[i] += adder[i];

	for (int i{ 0 }; i < addend.size() - 1; i++)
		if (addend[i] >= 10)
		{
			addend[i] -= 10;
			addend[i + 1]++;
			times++;
		}

	if (addend[addend.size() - 1] >= 10)
	{
		addend[addend.size() - 1] -= 10;
		addend.push_back(1);
		times++;
	}
}
```

</details>

[source code](v2(AC).cpp)

## <ruby>Optimization<rt>*優化*</rt></ruby> Points:
1. ### Removed Dead Code: 
> * Deleted the confusing and broken ``c = a + b`` loop logic.
2. ### Prevented <ruby>Out-of-Bounds<rt>*陣列越界*</rt><ruby>: 
> * Added `if (a < b) swap(a, b)` to ensure addend is always longer than adder.<br>
> * Limit the addition loop to `adder.size()` to avoid out-of-bounds.
<details>
<summary> <head>click to open(v1)<head> </summary>

for (int i = <ruby>~~addend~~<rt>adder</rt><ruby>.size() - 1; i >= 0; i--)
		addend[i] += adder[i];

</details>

3. ### Reduced Overhead: 
> * Used global vectors. V1 passed vectors by value <sub>copying them every time</sub>, which wasted memory and time.
4. ### Fixed Output Grammar:
> * Added a specific check for "1 carry operation", fixing a strict judge error.

## Complexity Analysis
- Time complexity： *O(N \* C)
- Space complexity： *O(1)

> [!Note]
> 1. 真的不行就看中文版。
> 2. **不要緊張！！！不要緊張！！！不要緊張！！！**
> 💡 緊張就會亂思路！
> 3. 寫完發現有問題不要東拼西湊，重看邏輯哪裡有問題！
> 4. 多考慮一些，瘋狂程式的要求很高！換行都會要求！