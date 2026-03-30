# 10420 - List of Conquests

## 題目URL -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=1361)

## 簡介:
給定 $T$ 行字串，每一行代表 Don Giovanni 愛過的女人記錄。每行的第一個單字是「國家」，後面的字串是「女人的名字」。
我們的任務是：**統計每個國家出現的次數，並將國家名稱按照字母順序 (Alphabetical order) 排序輸出。**

<details>
<summary><head>點擊查看C++ std::map</head></summary>

### 為什麼這題是 std::map 的主場？
這題有兩個核心需求：「統計出現次數」與「按字母排序」。
使用 `std::map<string, int>` 擁有兩個無可取代的優勢：
1. **動態擴充與自動計數**：當我們寫下 `count[country]++` 時，如果該國家是第一次出現，`map` 會自動建立該標籤並預設數量為 0，接著執行 `++` 變成 1。完全不需要手動檢查國家是否存在，也不需要預先宣告陣列大小！
2. **自帶排序屬性**：`map` 的底層實作是紅黑樹 (Red-Black Tree)，這代表它**永遠會根據 Key (國家名稱) 自動按照字母的 A 到 Z 排好序**。我們不需要寫任何 `sort()` 函式，走訪輸出時就已經完美符合題意。

### 讀取技巧：神準切割「國家」與「名字」
題目保證國家名稱只有「一個單字」。
利用 `cin` 讀取字串時「遇到空白或換行就會停止，且會自動跳過開頭空白」的特性，我們可以直接用 `cin >> country;` 精準抓下每行的第一個單字（國家）。
接著，使用 `getline(cin, girl);` 將該行剩餘的女人名字全部吃掉（當作垃圾處理），省去了所有繁瑣的字串切割邏輯，也巧妙避開了換行符號的干擾。

</details>

## Thinking

### variable reference:
| variable | meaning |
| :--- | :--- |
| `T` | The total number of records (lines) to process |
| `count` | A `std::map<string, int>` storing the country as the Key and its frequency as the Value |
| `country` | The first word of each line, representing the country name |
| `girl` | The remainder of the line (the woman's name), which is ignored in the logic |

<details>
<summary><head>點擊查看中文版</head></summary>

| 變數 | 說明 |
| :--- | :--- |
| `T` | 總共需要處理的資料行數 |
| `count` | 統計字典，Key 存國家名稱，Value 存出現次數 |
| `country` | 每行的第一個單字 (國家名稱) |
| `girl` | 每行剩下的字串 (女人的名字)，讀取後直接捨棄 |

</details>

### version 1 - 邏輯:
```text
1. Read the total number of records T
2. Create a std::map<string, int> named count
3. Loop T times:
4.      Read the first word into 'country' using cin
5.      Read the rest of the line into 'girl' using getline and ignore it
6.      Increment the count for the specific country: count[country]++
7. Iterate through the map (which is automatically sorted by key):
8.      Print the country name (it.first) and its count (it.second)
```

<details>
<summary><head>點擊查看中文版</head></summary>

```text
1. 讀取總行數 T
2. 宣告一個 map 字典 count，負責綁定 <國家, 次數>
3. 執行 T 次迴圈：
4.      利用 cin 讀取第一個單字存入 country
5.      利用 getline 讀取整行剩餘的字串存入 girl (直接捨棄)
6.      將該國家的計數器加 1：count[country]++
7. 利用 for-each 迴圈走訪 map (底層已自動按字母排好序)：
8.      輸出 國家名稱(it.first) 與 出現次數(it.second)
```
</details>

## 複雜度分析

| 版本 | 時間複雜度 | 空間複雜度 |
| :--- | :--- | :--- |
| V1 | $O(N \log K)$ | $O(K)$ |

* 註：$N$ 為總資料行數，$K$ 為相異的國家數量。每次在 `map` 中尋找或插入字串的時間複雜度為 $O(\log K)$，總共執行 $N$ 次。空間複雜度則取決於有多少個不同的國家被存入 `map` 中。

## 版本總結

| 特性 | V1 (std::map 統計法) |
| :--- | :--- |
| 資料結構 | 關聯式容器 `std::map<string, int>` |
| 核心思維 | 利用 `map` 的動態擴充與自帶紅黑樹排序特性 |
| 字串處理 | 利用 `cin` 切割首個單字，利用 `getline` 消耗剩餘行 |
| 邏輯複雜度 | 極低，完全免去手動尋找索引與 `sort()` 的麻煩 |