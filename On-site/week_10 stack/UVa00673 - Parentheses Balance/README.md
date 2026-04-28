# 00673 - Parentheses Balance

## 題目URL -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=8&page=show_problem&problem=614)

## 簡介
**括號匹配**問題，主要考察對 **資料結構 —— 堆疊 (Stack)** 的應用。
題目會給定一個字串，裡面可能包含小括號 `()` 和中括號 `[]`。我們需要判斷該字串中的括號是否「完全平衡且配對正確」。

## Thinking
### variable reference:
| variable | meaning |
| :--- | :--- |
| `Case` | Number of test cases |
| `s` | The string for each test case containing parentheses |
| `parentheses` | A stack used to store unpaired parentheses |
| `c` | Each character when iterating through the string `s` |

<details>
<summary><head>點擊查看中文版</head></summary>

| 變數 | 說明 |
| :--- | :--- |
| `Case` | 測試資料的數量 |
| `s` | 每一筆測試資料的括號字串 |
| `parentheses` | 用來儲存尚未配對的括號的堆疊 |
| `c` | 讀取字串 `s` 時的每一個字元 |

</details>

### version 1 - 邏輯:

```text
READ test cases count 'Case'
WHILE Case--:
    READ string 's'
    INIT empty stack 'parentheses'

    FOR EACH character 'c' in 's':
        // Rule 1: Left brackets or empty stack
        IF 'c' == '(' || 'c' == '[' || 'st' is empty:
            PUSH 'c'
        
        // Rule 2: Right brackets matching
        ELSE IF 'c' == ']':
            IF st.top() == '[' THEN POP
            ELSE PUSH 'c'
            
        ELSE IF 'c' == ')':
            IF st.top() == '(' THEN POP
            ELSE PUSH 'c'

    // Final Validation
    IF 'parentheses' is empty:
        PRINT "Yes"
    ELSE:
        PRINT "No"
```
<details>
<summary><head>點擊查看中文版</head></summary>

```text
讀取 測資數量 'Case'
當 Case--：
    讀取 字串 's'
    初始化 空堆疊 'parentheses'

    對於 's' 中的每個字元 'c'：
        // 規則一：左括號或空堆疊，無條件推入
        如果 'c' == '(' || 'c' == '[' || 'st' 為空：
            PUSH 'c'
        
        // 規則二：右括號配對檢查
        否則如果 'c' == ']'：
            如果 st.top() == '[' 則 POP (配對成功)
            否則 PUSH 'c' (配對失敗，當作殘留物)
            
        否則如果 'c' == ')'：
            如果 st.top() == '(' 則 POP (配對成功)
            否則 PUSH 'c' (配對失敗，當作殘留物)

    // 最終驗證
    如果 'parentheses' 為空：
        輸出 "Yes" (完美消除)
    否則：
        輸出 "No"
```
</details>

### version 2 - 邏輯:
```text
1. Define struct Point { double x, y }
2. while cin >> 4 Points (a, b, c, d)
3.      sumX = a.x + b.x + c.x + d.x
4.      sumY = a.y + b.y + c.y + d.y
5.      Use if/else to find the identical point and store it in samePoint (C)
6.      Print (sumX - 3 * samePoint.x) and (sumY - 3 * samePoint.y) formatted to 3 decimal places
```

<details>
<summary><head>點擊查看中文版</head></summary>

```text
1. 定義結構體 Point 包含 x 和 y 座標
2. 讀取 4 個 Point (a, b, c, d) 直到 EOF
3.      計算 4 個點的 x 座標總和 sumX
4.      計算 4 個點的 y 座標總和 sumY
5.      使用 if/else 找出座標相同的點，並存入 samePoint (即交點 C)
6.      利用優化公式 (Sum - 3C)，精準輸出小數點後 3 位的座標
```
</details>

## 複雜度分析

| 特性 | 複雜度 |
| :--- | :--- |
| Time Complexity | $O(N)$ per test case (where N is the length of the string) |
| Space Complexity | $O(N)$ per test case (in the worst case where all characters are pushed onto the stack) |

<details>
<summary><head>點擊查看中文版</head></summary>

| 特性 | 複雜度 |
| :--- | :--- |
| 時間複雜度 | $O(N)$ 每個測資 (N 為字串長度) |
| 空間複雜度 | $O(N)$ 每個測資 (最差情況下所有字元均壓入堆疊) |

</details>