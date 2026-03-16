# 0169 - Majority Element

## 題目URL -> [here](https://leetcode.com/problems/majority-element/)

## Introduction:
The core of this problem is to find the majority element that appears more than $\lfloor n / 2 \rfloor$ times in an array. Since it is guaranteed that the majority element always exists, we can use two approaches: 
1. **Sorting:** Sorting the array ensures that the middle element is the majority element.
2. **Boyer-Moore Voting Algorithm:** Using a count-and-cancel logic, different elements cancel each other out, and the majority element will always survive at the end.

<details>
<summary><head>點擊查看中文版</head></summary>

核心是找出陣列中出現次數超過 $\lfloor n / 2 \rfloor$ 的多數元素。因為題目保證該元素必定存在，我們可以使用兩種策略：
1. **排序法：** 
`利用sort`將陣列從小到大排序後，正中間的元素必定是多數元素。
2. **Boyer-Moore 投票演算法：** 
透過不同元素互相抵銷的邏輯，因為多數元素的數量超過一半，最後存活下來的一定是它。

<details>
<summary><head>點擊查看演算法詳情</head></summary>

## core logic：一換一的*抵銷*
這個演算法能成立的唯一大前提是：`目標數字的數量，保證超過陣列總長度的一半 ($> \lfloor n/2 \rfloor$)`<br>
一換一下來，超過一半的那個目標數一定會存活到最後

## 實際演練 (Dry Run)：
假設輸入陣列是 [2, 2, 1, 1, 1, 2, 2]，要找的多數是 2

第 1 個兵 `2`：majority = 2, count = 1

第 2 個兵 `2`：majority = 2, count = 2

第 3 個兵 `1`：majority = 2, count = 1 
> //2被1消耗了

第 4 個兵 `1`：majority = 2, count = 0 
> //2被1消耗完了，輪到1佔據主場

第 5 個兵 `1`：majority = 1, count = 1

第 6 個兵 `2`：majority = 1, count = 0 
> //2再次消耗完1，最終佔據主場直到最後

第 7 個兵 `2`：majority = 2, count = 1
</details>
</details>

## Thinking
### variable reference:
| variable | meaning |
| :--- | :--- |
| `nums` | The input vector containing the sequence of numbers |
| `majority` | The current candidate for the majority element (used in Version 2) |
| `count` | The counter representing the "lives" or "votes" of the candidate (used in Version 2) |

### version 1 - 邏輯 (Sorting):
```text
1. sort(nums.begin(), nums.end()) // Sort the entire array in ascending order
2. return nums[nums.size() / 2] // The middle element is guaranteed to be the majority
```
<details>
<summary><head>點擊查看中文版</head></summary>

```text
1. 利用 sort() 將 nums 陣列從小到大排序
2. 因為多數元素的數量超過一半，排序後正中間的元素 nums.size() / 2 必定是多數元素，直接回傳
```
</details>

### version 2 - 邏輯 (Boyer-Moore Voting Algorithm):
```text
1. Initialize majority = nums[0], count = 1
2. for i = 1 to nums.size() - 1 // Traverse the rest of the array
3.      count = (majority == nums[i]) ? count += 1 : count -= 1 // Match adds vote, mismatch subtracts
4.      if count == 0 // The candidate's votes drop to zero
5.          majority = nums[i] // New candidate steps up
6.          count++ // Reset vote
7. return majority
```
<details>
<summary><head>點擊查看中文版</head></summary>

```text
1. 初始化 majority 為第一個數字，count 為 1
2. 迴圈從第二個數字 (i = 1) //開始遍歷陣列
3.      如果遇到同陣營數字 count 加 1，否則 count 減 1 //一換一抵銷
4.      如果 count 歸零 //兵力被消耗光了
5.          將當前數字設為新的候選人 majority
6.          將 count 重新加 1
7. 迴圈結束後，回傳存活到最後的 majority
```
</details>

## Complexity
### Time Complexity: 
* **Version 1:** $O(N \log N)$ - Due to the time taken by the built-in sorting algorithm.
* **Version 2:** $O(N)$ - Only requires a single pass through the array.
### Space Complexity: 
* **Version 1:** $O(1)$ or $O(\log N)$ - Depending on the underlying sorting implementation in C++.
* **Version 2:** $O(1)$ - Only uses two standard variables (`majority` and `count`), regardless of the input size.

<details>
<summary><head>點擊查看中文版</head></summary>

### Time Complexity: 
* **Version 1:** $O(N \log N)$ - 因為內建排序演算法所需的時間。
* **Version 2:** $O(N)$ - 只需要將陣列從頭到尾遍歷一次。
### Space Complexity: 
* **Version 1:** $O(1)$ 或 $O(\log N)$ - 取決於 C++ 底層排序演算法的實作方式。
* **Version 2:** $O(1)$ - 只使用了兩個基本變數，不會因為陣列變大而佔用更多記憶體。
</details>