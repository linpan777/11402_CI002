# 10242 - Fourth Point!!

## 題目URL -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=23&page=show_problem&problem=1183)

## Introduction:
The core of this problem is "geometric computation" or "parallelogram property." Given three vertices of a rectangle/parallelogram (where one point appears twice among four input points), we need to find the fourth vertex. The key insight is using the parallelogram property: for a parallelogram with vertices A, B, C, D, the diagonals bisect each other, so the fourth point can be calculated as **D = A + B - C**, where C is the duplicated point.

<details>
<summary><head>點擊查看中文版</head></summary>

核心是「幾何計算」或「平行四邊形性質」。給定矩形/平行四邊形的三個不同頂點（輸入四個點中有一個重複），需要找出第四個頂點。關鍵洞察是利用平行四邊形性質：對於平行四邊形的四個頂點，對角線會互相平分，因此第四點可以計算為 **D = A + B - C**，其中 C 是重複的點。

> **一句話筆記：給四個點找出第四個頂點，利用平行四邊形的對角線互相平分性質：第四點 = A + B - C（C 為重複點）。**
</details>

## Thinking
### variable reference:
| variable | meaning |
| :--- | :--- |
| `Point` | A struct containing `x` and `y` coordinates |
| `a, b, c, d` | The four input points |
| `samePoint` | The point that appears twice (one vertex of the parallelogram) |
| `sumX, sumY` | The sum of x and y coordinates of all four points |

<details>
<summary><head>點擊查看中文版</head></summary>

### 變數參考：
| variable | meaning |
| :--- | :--- |
| `Point` | 包含 `x` 和 `y` 座標的結構體 |
| `a, b, c, d` | 四個輸入的點 |
| `samePoint` | 重複出現的點（平行四邊形的一個頂點） |
| `sumX, sumY` | 四個點的 x 和 y 座標的總和 |
</details>

## 邏輯:
```text
1. Read four points (a, b, c, d)
2. Calculate sum of all x-coordinates and y-coordinates
3. Find which point is duplicated (appears twice)
4. Apply parallelogram formula: 
   - Fourth Point = (sumX, sumY) - 2*(duplicated point)
5. Output the fourth point with 3 decimal places
```

<details>
<summary><head>點擊查看中文版</head></summary>

```text
1. 讀取四個點 (a, b, c, d)
2. 計算所有點的 x 座標總和與 y 座標總和
3. 找出哪一個點重複出現（出現兩次）
4. 應用平行四邊形公式：
   - 第四點 = (sumX, sumY) - 2*(重複的點)
5. 輸出第四點，精度至小數點第 3 位
```
</details>

## Complexity
### Time Complexity: $O(1)$
> Each test case involves only constant-time operations: 4 point comparisons and 4 arithmetic operations per case.
### Space Complexity: $O(1)$
> Only a fixed number of variables are used regardless of input size.

<details>
<summary><head>點擊查看中文版</head></summary>

### Time Complexity: $O(1)$
> 每個測資只涉及常數時間的操作：4 個點的比較和 4 次算術運算。
### Space Complexity: $O(1)$
> 不管輸入大小如何，只使用固定數量的變數。
</details>
