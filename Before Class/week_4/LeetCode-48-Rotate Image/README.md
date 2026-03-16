# 0048 - Rotate Image

## 題目URL -> [here](https://leetcode.com/problems/rotate-image/)

## Introduction:
The core of this problem is to rotate an $n \times n$ 2D matrix by 90 degrees clockwise *in-place*. Instead of mathematically calculating and moving elements one by one to their new coordinates, an elegant and common approach is to break the transformation down into two simple steps: 
1. We can solve this by applying two operations to the matrix: transposing and reversing

<details>
<summary><head>點擊查看中文版</head></summary>

核心是將一個 $n \times n$ 的二維矩陣順時針旋轉 90 度，且題目要求必須 `原地 (in-place)`修改矩陣
1. 將矩陣透過轉置、反轉兩個操作來進行解題

<details>
<summary><head>點擊查看演算法詳情</head></summary>

## core logic：先轉置，後反轉
轉置會把`列`變成`行`，此時方向雖然對了，但左右是顛倒的，所以最後再針對每一列進行反轉即可

## 實際演練 (Dry Run)：
假設輸入矩陣是一個 $3 \times 3$ 的矩陣：<br>
`[1, 2, 3]`<br>
`[4, 5, 6]`<br>
`[7, 8, 9]`

**Step 1: 轉置 (Transpose)**
沿著對角線 (1, 5, 9) 交換兩側的元素 (例如 2 和 4 換，3 和 7 換)。
矩陣變成：<br>
`[1, 4, 7]`<br>
`[2, 5, 8]`<br>
`[3, 6, 9]`

**Step 2: 反轉每一列 (Reverse each row)**
把第一列 `[1, 4, 7]` 顛倒變成 `[7, 4, 1]`，以此類推。
矩陣變成：<br>
`[7, 4, 1]`<br>
`[8, 5, 2]`<br>
`[9, 6, 3]`

> // 成功完成 90 度順時針旋轉
</details>
</details>

## Thinking
### variable reference:
| variable | meaning |
| :--- | :--- |
| `matrix` | The input 2D vector representing the $n \times n$ image |
| `n` | The size of the matrix's rows and columns |
| `i`, `j` | The loop counters used for iterating through the rows and columns |

<details>
<summary><head>點擊查看中文版</head></summary>

| variable | meaning |
| :--- | :--- |
| `matrix` | 代表 $n \times n$ 圖片的輸入二維陣列 |
| `n` | 矩陣的長寬維度大小 |
| `i`, `j` | 用於遍歷矩陣列與行的迴圈計數器 |
</details>

### version 1 - 邏輯 (Transpose + Reverse):
```text
1. Get the size n of the matrix.
2. for i = 0 to n - 1
3.      for j = i to n - 1 // Start j from i to only swap across the diagonal once
4.          swap(matrix[i][j], matrix[j][i]) // Step 1: Transpose
5. for i = 0 to n - 1
6.      reverse(matrix[i].begin(), matrix[i].end()) // Step 2: Reverse each row
```
<details>
<summary><head>點擊查看中文版</head></summary>

```text
1. 取得矩陣的大小 n
2. 第一個迴圈遍歷列 (i 從 0 到 n - 1)
3.      內層迴圈遍歷行 (j 從 i 到 n - 1) // 注意 j 從 i 開始，確保對角線兩側只交換一次，否則會換回原樣
4.          將 matrix[i][j] 與 matrix[j][i] 互換 // 完成 Step 1: 轉置
5. 第二個迴圈再次遍歷列 (i 從 0 到 n - 1)
6.      呼叫 reverse 函式將第 i 列從頭到尾反轉 // 完成 Step 2: 反轉
```
</details>

## Complexity
### Time Complexity: 
* **Version 1:** $O(N^2)$ - We iterate through all elements in the $N \times N$ matrix twice (once for the transpose, once for the reverse). Since the total number of elements is $N^2$, the time is proportional to $N^2$.
### Space Complexity: 
* **Version 1:** $O(1)$ - The rotation is performed strictly in-place. We only use a few integer variables for loop counting and swapping, regardless of the matrix size.

<details>
<summary><head>點擊查看中文版</head></summary>

### Time Complexity: 
* **Version 1:** $O(N^2)$ - 我們將 $N \times N$ 矩陣中的所有元素大約遍歷了兩次（一次轉置，一次反轉）。因為總元素量為 $N^2$，所以時間複雜度與 $N^2$ 成正比。
### Space Complexity: 
* **Version 1:** $O(1)$ - 旋轉過程完全是「原地」進行的。除了迴圈計數器和交換用的暫存空間外，我們沒有宣告任何額外的二維陣列，記憶體消耗不隨矩陣大小改變。
</details>