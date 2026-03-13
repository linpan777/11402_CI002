# 12149 - Feynman

## 題目URL -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3296)

## Introduction:
The core of this problem is to calculate the total number of squares of all sizes within an $N \times N$ grid. 
1. The pattern is simply the sum of squares of all integers from 1 to $N$. We can use a loop to accumulate $i^2$ for $i$ from $N$ down to 1, and stop the program when the input is 0.

<details>
<summary><head>點擊查看中文版</head></summary>

核心是計算在一個 $N \times N$ 的棋盤中，總共有多少個不同大小的正方形。
1. 其規律剛好是 1 到 $N$ 的平方和。我們可以使用迴圈，將 $i$ 從 $N$ 遞減到 1，並把每次的 $i^2$ 累加起來，當輸入為 0 時結束程式。
</details>

## Thinking
### variable reference:
| variable | meaning |
| :--- | :--- |
| `Case` | Represents the number $N$ given by the problem (the number of squares in each side of the grid) |
| `answer` | The accumulated total number of different squares |

## 邏輯:
```text
1. while cin Case // Read the grid size N
2.      if Case == 0 // The end of input is indicated by a zero
3.          return 0 // Terminate the program
4.      int answer = 0
5.      for(i = Case; i > 0; i--) // Loop from N down to 1
6.          answer += i * i // Add the number of squares of size i x i
7.      cout answer // Output the total number of squares
```

<details>
<summary><head>點擊查看中文版</head></summary>

```text
1. while cin Case // 讀取棋盤大小 N
2.      if Case == 0 // 當輸入為 0 時代表結束
3.          return 0 // 結束程式
4.      int answer = 0 // 初始化總和為 0
5.      for(i = Case; i > 0; i--) // 從 N 遞減到 1
6.          answer += i * i // 累加各種大小正方形的數量 (i 的平方)
7.      cout answer // 輸出總數
```
</details>

## Complexity
### Time Complexity: $O(N)$
> Where $N$ is the grid size (`Case`). The loop executes $N$ times to calculate the sum of squares. *(Advanced tip: This can be optimized to $O(1)$ by using the mathematical formula for the sum of squares: $N(N+1)(2N+1)/6$)*.
### Space Complexity: $O(1)$
> Only a few standard variables (`Case`, `answer`) are used, which takes constant memory space regardless of the input size.

<details>
<summary><head>點擊查看中文版</head></summary>

### Time Complexity: $O(N)$
> $N$ 為輸入的棋盤大小 (`Case`)。迴圈會執行 $N$ 次來計算平方和。*(進階提示：如果改用數學的平方和公式 $N(N+1)(2N+1)/6$，時間複雜度可以降為 $O(1)$)*。
### Space Complexity: $O(1)$
> 只需要使用幾個基本變數 (`Case`, `answer`) 來計算，無論輸入的數字多大，佔用的記憶體空間都是固定的常數。
</details>