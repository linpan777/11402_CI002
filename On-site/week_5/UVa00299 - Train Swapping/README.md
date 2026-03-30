# 00299 - Train Swapping

## 題目URL -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=4&page=show_problem&problem=235)

## 簡介:
給定一列火車車廂的初始排列順序，火車長只能透過「交換相鄰的兩節車廂」來重排它們。
目標是計算出：**最少需要交換幾次**，才能讓車廂按照 `1, 2, 3... N` 的順序排好？
1. **核心演算法**：這題完美契合經典的**氣泡排序法 (Bubble Sort)**。因為氣泡排序的本質就是「只交換相鄰的元素」，所以排序過程中發生的交換總次數，就是題目的解答。

<details>
<summary><head>點擊查看 氣泡排序法 (Bubble Sort) 的原理與優化</head></summary>

### 為什麼這題是氣泡排序的主場？
題目特別強調「相鄰交換 (swapping two trains adjacent to each other)」。
氣泡排序的運作邏輯，正是每次比較相鄰的兩個數字，如果左邊比右邊大，就把它們對調。這與題目的物理限制完全一致，因此我們只要實作氣泡排序，並在每次執行 `swap` 時順便將計數器 `+1`，就能得到正確答案。

### 內迴圈的極致優化：`j < how_many_train - 1 - i`
在實作雙層迴圈時，內層迴圈的條件寫法非常關鍵：
```cpp
for(int i{0}; i < how_many_train; i++)
    for (int j{ 0 }; j < how_many_train - 1 - i; j++) // 優化關鍵在這裡
```
**為什麼要減 `i`？**
因為氣泡排序每一輪（外層迴圈每跑一次），都會把當前範圍內「最大（最重）」的數字像氣泡一樣推到陣列的最右端。
- 第一輪結束後，最大的數字已經固定在最後一格了。
- 第二輪結束後，第二大的數字固定在倒數第二格。
因此，隨著 `i` 的增加，右邊已經排好的數字越來越多，內層迴圈就不需要再去檢查那些已經固定好的車廂了！減去 `i` 可以大幅減少不必要的比較次數。

</details>

## Thinking

### variable reference:
| variable | meaning |
| :--- | :--- |
| `T` | The number of test cases |
| `how_many_train` | The total number of train carriages (length of the train) |
| `train` | A `std::vector<int>` storing the current order of the carriages |
| `count` | A counter to track the total number of adjacent swaps performed |

<details>
<summary><head>點擊查看中文版</head></summary>

| 變數 | 說明 |
| :--- | :--- |
| `T` | 測試資料的總筆數 |
| `how_many_train` | 火車車廂的總數量 (陣列長度) |
| `train` | 使用 `vector` 儲存火車車廂目前的排列狀態 |
| `count` | 計數器，用來記錄總共執行了幾次相鄰交換 |

</details>

### version 1 - 邏輯:
```text
1. Read the number of test cases T
2. Loop T times:
3.      Read the number of trains (how_many_train)
4.      Read the sequence of trains into a vector
5.      Initialize swap count = 0
6.      Perform Bubble Sort:
7.          Outer loop i from 0 to how_many_train - 1
8.          Inner loop j from 0 to how_many_train - 1 - i
9.              If train[j] > train[j + 1]:
10.                 Swap them
11.                 count++
12.     Print the formatted result with the swap count
```

<details>
<summary><head>點擊查看中文版</head></summary>

```text
1. 讀取測資筆數 T
2. 執行 T 次迴圈處理每組測資：
3.      讀入車廂總數量 how_many_train
4.      利用迴圈將車廂的初始順序讀入 train vector 中
5.      初始化交換計數器 count = 0
6.      執行氣泡排序法：
7.          外迴圈 i 控制回合數
8.          內迴圈 j 負責相鄰兩兩比較 (優化：減去已排好的 i 個)
9.              如果左邊車廂 > 右邊車廂：
10.                 使用 swap 交換位置
11.                 計數器 count + 1
12.     依照題目要求格式，印出總交換次數
```
</details>

## 複雜度分析

| 版本 | 時間複雜度 | 空間複雜度 |
| :--- | :--- | :--- |
| V1 | $O(N^2)$ per test case | $O(N)$ |

* 註：$N$ 為火車車廂的數量 (`how_many_train`)。氣泡排序法需要使用雙層迴圈進行相鄰比較，最壞情況下時間複雜度為 $O(N^2)$。因為題目限制 $L \le 50$，所以 $N^2$ 最大僅為 $2500$，執行速度極快。空間複雜度則取決於儲存車廂數列的 vector 長度 $O(N)$。

## 版本總結

| 特性 | V1 (Bubble Sort 版) |
| :--- | :--- |
| 核心演算法 | 氣泡排序法 (Bubble Sort) |
| 交換實作 | 完美利用 C++ 內建的 `std::swap` |
| 效能優化 | 內迴圈條件 `- i` 避開多餘的比較操作 |
| 空間管理 | 使用動態陣列 `std::vector`，並透過 `push_back` 存入 |
| 邏輯複雜度 | 直觀，非常適合模擬實體物件的相鄰交換 |