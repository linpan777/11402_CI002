# 0048 - Rotate Image

## 題目URL -> [here](https://leetcode.com/problems/rotate-image/)

## Introduction:
The core of this problem is to rotate an $n \times n$ 2D matrix by 90 degrees clockwise *in-place*. Instead of mathematically calculating and moving elements one by one to their new coordinates, an elegant and common approach is to break the transformation down into two simple steps: 
1. **Transpose:** Swap the matrix elements symmetrically across the main diagonal.
2. **Reverse:** Reverse the elements of each individual row horizontally.

<details>
<summary><head>點擊查看中文版</head></summary>

核心是將一個 $n \times n$ 的二維矩陣順時針旋轉 90 度，且題目要求必須「原地 (in-place)」修改矩陣。與其繁瑣地計算座標並逐一搬移元素，一個非常經典且優雅的解法是將動作分為兩步：
1. **轉置 (Transpose)：** 將矩陣沿著主對角線進行翻轉（交換元素）。
2. **反轉 (Reverse)：** 將每一列 (row) 的元素進行水平反轉。

<details>
<summary><head>點擊查看演算法詳情</head></summary>

## core logic：先轉置，後反轉
這個做法的巧妙之處在於利用簡單的矩陣操作組合出旋轉的效果。轉置會把「列」變成「行」，此時方向雖然對了，但左右是顛倒的，所以最後再針對每一列進行反轉即可。

## 實際演練 (Dry Run)：
假設輸入矩陣是一個 $3 \times 3$ 的矩陣：
`[1, 2, 3]`
`[4, 5, 6]`
`[7, 8, 9]`

**Step 1: 轉置 (Transpose)**
沿著對角線 (1, 5, 9) 交換兩側的元素 (例如 2 和 4 換，3 和 7 換)。
矩陣變成：
`[1, 4, 7]`
`[2, 5, 8]`
`[3, 6, 9]`

**Step 2: 反轉每一列 (Reverse each row)**
把第一列 `[1, 4, 7]` 顛倒變成 `[7, 4, 1]`，以此類推。
矩陣變成：
`[7, 4, 1]`
`[8, 5, 2]`
`[9, 6, 3]`

> // 成功完成 90 度順時針旋轉！
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