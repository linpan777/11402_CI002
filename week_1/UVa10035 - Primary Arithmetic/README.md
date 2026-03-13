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
### 1. Removed Dead Code: 
* Deleted the confusing and broken ``c = a + b`` loop logic.
### 2. Prevented <ruby>Out-of-Bounds<rt>*陣列越界*</rt><ruby>: 
* Added `if (a < b) swap(a, b)` to ensure addend is always longer than adder.<br>
* Limit the addition loop to `adder.size()` to avoid out-of-bounds.
<details>
<summary> <head>click to open(v1)<head> </summary>

for (int i = <ruby>~~addend~~<rt>adder</rt><ruby>.size() - 1; i >= 0; i--)
		addend[i] += adder[i];

</details>

### 3. Reduced Overhead: 
* Used global vectors. V1 passed vectors by value <sub>copying them every time</sub>, which wasted memory and time.
### 4. Fixed Output Grammar:
* Added a specific check for "1 carry operation", fixing a strict judge error.

## Complexity Analysis
- Time complexity： *O(N \* C)
- Space complexity： *O(1)

## Version 3
<details>
<summary>Click to see abot v3</summary>

## Thinking
### variable reference
| variable | meaning |
| :--- | :--- |
| `first` | input number 1 |
| `second` | input number 2 |
| `answer` | first%10 + second%10 |
| `times` | carry times |
| `carry` | Check if there is a current carry |

### Algorithm logic
```text
main:
1. Read 'first' and 'second'. Stop if both are 0.
2. Initialize 'times' = 0 and 'carry' = false for each test case.
3. If 'first' < 'second', swap them so 'first' is always the larger/longer number.
4. While 'first' is not 0:
5.      Calculate current digit sum: (first % 10) + (second % 10) + (1 if carry is true, else 0)
6.      If sum >= 10:
7.          Increment 'times' by 1
8.          Set 'carry' to true
9.      Else:
10.         Set 'carry' to false
11.     Divide both 'first' and 'second' by 10 (remove the last digit)
12. Print the properly formatted result based on 'times'
```
<details>
<summary> <head>點擊查看中文版<head> </summary>

```text
1. 讀取 'first' 和 'second'。若兩者皆為 0 則結束程式。
2. 針對每筆測資，初始化 進位次數 (times) = 0 與 當前進位狀態 (carry) = false。
3. 如果 'first' < 'second'，將兩者交換，確保 'first' 永遠是位數較長的數字。
4. 當 ('first' 不為 0) 時：
5.      計算當前個位數總和：(first % 10) + (second % 10) + (若 carry 為 true 則加 1，否則不加)
6.      如果總和 >= 10：
7.          進位次數 (times) + 1
8.          將進位狀態 (carry) 設為 true
9.      否則：
10.         將進位狀態 (carry) 設為 false
11.     將 'first' 與 'second' 同時除以 10 (削掉最後一位數字)
12. 根據進位次數，印出對應單/複數的結果字串
```
</details>

## Optimization point:
### 1.Space Complexity Optimization:<br>
- Deleted vector. Used variables (like bool carry) to track whether is carry or not, achieving zero extra space overhead.

### 2. Improved Time Efficiency (Single-pass computation):<br>
- Shifted from a two-step "store then add" approach to an "<ruby>on-the-fly<rt>及時</rt></ruby> calculation". This avoids the cost of dynamic array
<ruby>allocations<rt>*分配*</rt></ruby> (push_back) and processes everything in a single loop.

### 3. Cleaner Code Structure (Clean Code):<br>
- Removed the redundant external ``add()`` function and perfectly <ruby>integrat<rt>*結合*</rt></ruby> `? :` to handle the carry logic within a sisngle ``while`` loop, improving readability.

## Complexity Analysis
- Time complexity： $O(\log_{10}(\max(A, B)))$
- Space complexity： *O(1)

</details>

> [!Note]
> 1. 真的不行就看中文版。
> 2. 超好笑，這題初始寫法根本大砲打蚊子，用的是大數加法的作法。
> 3. 不知道寫這樣是不是對的...:( 一直在考慮要不要加個中文版