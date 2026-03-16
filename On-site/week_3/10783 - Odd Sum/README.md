# 10783 - Odd Sum

## 題目URL -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=19&page=show_problem&problem=1724)

## Introduction:
The core of this problem is to calculate the sum of all odd integers within a given range `[first, last]`. 
1. We can check if the starting point `first` is an even number; if it is, we increment it by 1 to make it odd. Then, we use a loop to accumulate the sum by adding 2 in each iteration until we reach or exceed `last`.

<details>
<summary><head>點擊查看中文版</head></summary>

核心是計算給定範圍 `[first, last]` 內所有奇數的總和。
1. 如果起點 `first` 是偶數，我們可以先將它加 1 調整為奇數，接著使用迴圈每次遞增 2，將範圍內的奇數累加起來，直到超過終點 `last`。
</details>

## Thinking
### variable reference:
| variable | meaning |
| :--- | :--- |
| `T` | The number of test cases |
| `first` | The starting integer of the given range |
| `last` | The ending integer of the given range |
| `sum` | The accumulated sum of all odd integers in the current range |
| `Case` | A global counter to track the current test case number for output formatting |

## 邏輯:
```text
1. cin T // Read the number of test cases
2. while T-- // Loop for each test case
3.      cin first, last // Read the range [first, last]
4.      int sum = 0
5.      if(first % 2 == 0) // If the start number is even
6.          first++ // Increment by 1 to make it odd
7.      for(i = first; i <= last; i += 2) // Step by 2 to iterate only odd numbers
8.          sum += i // Accumulate the odd numbers
9.      cout "Case ", ++Case, ": ", sum // Output the result in the required format
```

<details>
<summary><head>點擊查看中文版</head></summary>

```text
1. cin T // 讀取測資數量
2. while T-- // 執行 T 次迴圈
3.      cin first, last // 讀取起點與終點範圍
4.      int sum = 0 // 初始化總和為 0
5.      if(first % 2 == 0) // 如果起點是偶數
6.          first++ // 將其加 1 調整為奇數
7.      for(i = first; i <= last; i += 2) // 每次加 2，確保只跑奇數
8.          sum += i // 累加奇數
9.      cout "Case ", ++Case, ": ", sum // 依照題目要求格式輸出結果
```
</details>

## Complexity
### Time Complexity: $O(N)$
> Where $N$ is the difference between `last` and `first` ($N = last - first$). The loop only iterates through half of the numbers in the range (the odd ones), taking time proportional to the range size.
### Space Complexity: $O(1)$
> Only a few standard variables (`T`, `first`, `last`, `sum`, `Case`) are used, which takes constant memory space regardless of the input size.

<details>
<summary><head>點擊查看中文版</head></summary>

### Time Complexity: $O(N)$
> $N$ 為 `last` 與 `first` 之間的差值 ($N = last - first$)。迴圈只會跑範圍內一半的數字（也就是奇數），因此執行時間與範圍大小成正比。
### Space Complexity: $O(1)$
> 只需要使用幾個基本變數 (`T`, `first`, `last`, `sum`, `Case`) 來計算，無論輸入的數字多大，佔用的記憶體空間都是固定的常數。
</details>