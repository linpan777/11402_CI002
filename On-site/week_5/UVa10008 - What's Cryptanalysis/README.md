# 10008 - What's Cryptanalysis?

## 題目URL -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=949)

## 簡介:
給定 $T$ 行字串，要求統計所有英文字母（不分大小寫）出現的次數。
輸出規定：**按照出現次數由大到小排序；如果次數相同，則按照字母順序（A 到 Z）排序**。沒有出現的字母不輸出。
1. **核心概念**：字串處理、字元過濾、自訂排序規則。
2. **V1 (Bug 版) 警世範例**：展示了三個常見的新手地雷（過濾不乾淨導致越界、排序範圍錯誤、未處理平手規則）。
3. **V2 (標準 AC 版)**：使用 `struct` 綁定字母與次數，並配合 `std::sort` 與自訂 `cmp` 完美解決。
4. **V3 (天才降維版)**：不使用結構，也不呼叫 `sort`。利用紀錄「最大出現次數 (Max)」，並透過巧妙的雙層迴圈直接印出符合規定的答案。

<details>
<summary><head>點擊查看 V1 的三個致命地雷與 V2 的修正</head></summary>

### 地雷 1：危險的字元過濾
- **V1 寫法**：`else if (c > '0' && c < '9' || c == '\n') continue;`
- **錯誤原因**：這只擋掉了數字和換行。如果遇到標點符號（如 `.` 或 `,`）或空白，陣列索引 `c - 65` 會變成負數，導致 Runtime Error (陣列越界)。
- **V2 修正**：`else if (!isupper(c)) continue;` (確保只有大寫字母才處理，完美防禦！)

### 地雷 2：`sort` 範圍漏掉 'Z'
- **V1 寫法**：`sort(Char, Char + 25, cmp);`
- **錯誤原因**：C++ 的 `sort` 是左閉右開區間，`+ 25` 只會排到第 24 格（'Y'），'Z' 完全沒參與排序。
- **V2 修正**：改為 `sort(Char, Char + 26, cmp);`。

### 地雷 3：`cmp` 忘記處理平手
- **V1 寫法**：次數相同時直接回傳 `false`。
- **錯誤原因**：系統規定次數相同時要「按字母順序排」，V1 沒寫這條規則，會拿到 Wrong Answer。
- **V2 修正**：加上 `if (a.count != b.count)` 判斷，平手時回傳 `a.alpha < b.alpha`。

</details>

<details>
<summary><head>點擊查看 V3 (無 Sort 版) 的邏輯</head></summary>

### 為什麼 V3 可以不用 `sort`？
這是一種利用**「計數排序 (Counting Sort)」**思維的極致展現。
1. 在讀取字串時，我們順手記下所有字母中「出現最多次的次數 (Max)」。
2. 輸出時，外層迴圈 `i` 從 `Max` 開始往下遞減到 1（保證了**次數由大到小**）。
3. 內層迴圈 `j` 固定從 0 走到 25（代表 A 走到 Z，保證了平手時**字母由小到大**）。
4. 只要 `Char[j] == i`，就印出來！
**結論：完全不需要定義 `struct`，也不需要寫裁判函數，用最基礎的陣列和迴圈就完美符合了題目的兩大排序條件！**

</details>

## Thinking

### variable reference:
| variable | meaning |
| :--- | :--- |
| `T` | The number of test cases |
| `setences` | The string to store each line of input |
| `Char` | Array to store the frequency of each letter (Struct array in V1/V2, Int array in V3) |
| `Max` | <sub>Used in `V3`</sub> Tracks the highest frequency of any letter to set the loop bound |

<details>
<summary><head>點擊查看中文版</head></summary>

| 變數 | 說明 |
| :--- | :--- |
| `T` | 測試資料的行數 |
| `setences` | 用來儲存每一行輸入的字串 |
| `Char` | 紀錄字母出現次數的陣列 (V1/V2 是結構體陣列，V3 是純整數陣列) |
| `Max` | <sub>用於 `V3`</sub> 紀錄出現過最多次的數量，作為外層迴圈的起點 |

</details>

### version 2 (Struct+Sort) - 邏輯:
```text
1. Read T and use cin.ignore()
2. Loop T times to read sentences
3.      Convert lowercase to uppercase
4.      Filter out non-uppercase characters
5.      Increment the count in the Char struct array and assign the letter
6. Sort the Char array using a custom cmp function (count DESC, then alpha ASC)
7. Print letters with count > 0
```

### version 3 (No Sort) - 邏輯:
```text
1. Read T and use cin.ignore()
2. Loop T times to read sentences
3.      Convert lowercase to uppercase
4.      Filter out non-uppercase characters
5.      Increment count in the integer array Char[26]
6.      Update Max if the current count exceeds Max
7. Outer loop i from Max down to 1 (handles count DESC requirement)
8.      Inner loop j from 0 to 25 (handles alpha ASC requirement)
9.          If Char[j] == i, print the character and count
```

## 複雜度分析

| 版本 | 時間複雜度 | 空間複雜度 |
| :--- | :--- | :--- |
| V2 (Struct + Sort) | $O(L + K \log K)$ | $O(K)$ |
| V3 (純陣列解法) | $O(L + M \times K)$ | $O(K)$ |

* 註：$L$ 為所有字串的總長度，$K$ 為字母表大小 (26)，$M$ 為最大出現次數 (`Max`)。因為 $K$ 是常數 26，所以排序或雙層迴圈的時間消耗都極小，整體效能皆取決於字串長度 $O(L)$。

## 版本對比

| 特性 | V2 (標準解法) | V3 (降維解法) |
| :--- | :--- | :--- |
| 資料綁定 | 使用 `struct` 綁定字母與次數 | 純 `int` 陣列，利用索引代表字母 |
| 排序方式 | 呼叫 `<algorithm>` 的 `sort` + 自訂 `cmp` | 利用雙層迴圈的方向性自然達成排序 |
| 程式碼結構 | 較正式、模組化 (OOP 風格) | 極度精簡、暴力直觀 |
| 易錯點 | `cmp` 邏輯寫錯、`sort` 範圍給錯 | 忘記更新 `Max` |