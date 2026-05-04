# 1700 - Number of Students Unable to Eat Lunch

## 題目URL -> [here](https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/)

## 簡介
結合 **佇列 (Queue)** 與 **堆疊 (Stack)** 概念的模擬題。
模擬學校餐廳發放三明治的過程：三明治疊在桌上（Stack 屬性，只能拿最上面），而學生排成一列等著拿（Queue 屬性，最前面的人先拿）

**題目目標:**
給定代表學生喜好與三明治口味的陣列（`0` 代表圓形，`1` 代表方形），請計算出最後有**多少個學生吃不到三明治**

<details>
<summary><head>點擊查看`運作條件`與`結束條件`</head></summary>

### 運作規則：*
1. **配對成功：** 如果排在最前面的學生，想要的對應到最上面的三明治，就拿走三明治並離開隊伍
2. **配對失敗：** 如果他不喜歡最上面的三明治，就放棄拿取並走到**隊伍的最尾端**重新排隊

### 結束條件：  
當隊伍不斷循環，直到**隊伍中剩下的所有人，都不吃桌上最上面那份三明治**時，發放過程就會徹底卡死
**利用vaild**
</details>

## Thinking
### variable reference:

| variable | meaning |
| :--- | :--- |
| `one_std` | Number of students who prefer square sandwiches (type 1) |
| `one_sand` | Number of square sandwiches (type 1) |
| `student_q` | A queue storing the students' preferences in order |
| `sandwiche_q` | A queue storing the stack of available sandwiches |
| `vaild` | Counter tracking consecutive students who rejected the top sandwich (used to detect a deadlock) |

<details>
<summary><b>點擊查看中文版</b></summary>

| 變數 | 說明 |
| :--- | :--- |
| `one_std` | 喜歡方形三明治 (口味 1) 的學生總數 |
| `one_sand` | 方形三明治 (口味 1) 的總數 |
| `student_q` | 用來模擬學生排隊與喜好的佇列 (Queue) |
| `sandwiche_q` | 用來模擬桌上三明治擺放順序的佇列 (Queue) |
| `vaild` | 記錄「連續拒絕」拿取三明治的學生人數 (用來判斷迴圈是否卡死) |

</details>

</details>

### version 1 - 邏輯:

```text
INIT every var

// Step 1: Initialize queues and count preferences for type 1
FOR EACH student in 'students' array:
    IF student == 1 THEN INCREMENT 'one_std'
    PUSH student into 'student_q'

FOR EACH sandwich in 'sandwiches' array:
    IF sandwich == 1 THEN INCREMENT 'one_sand'
    PUSH sandwich into 'sandwiche_q'

// Step 2: Early exit optimization
IF 'one_std' == 'one_sand':
    RETURN 0

// Step 3: Queue Simulation
INIT counter 'vaild' to 0
WHILE 'vaild' < size of 'sandwiche_q':
    IF front of 'student_q' == front of 'sandwiche_q':
        POP from 'student_q'
        POP from 'sandwiche_q'
        SET 'vaild' to 0
    ELSE:
        PUSH front of 'student_q' to the back of 'student_q'
        POP from 'student_q'
        INCREMENT 'vaild'

// Step 4: Return hungry students
RETURN size of 'student_q'
```
<details>
<summary><head>點擊查看中文版</head></summary>

```text
初始化各項

// 步驟一：將資料推入佇列並統計口味 1 的數量
對於 'students' 陣列中的每個學生：
    如果 學生喜歡 1，則 'one_std' 加 1
    將 學生 推入 'student_q'
對於 'sandwiches' 陣列中的每個三明治：
    如果 三明治是 1，則 'one_sand' 加 1
    將 三明治 推入 'sandwiche_q'

// 步驟二：比較1是否相等(最佳化提早結束)
如果 'one_std' == 'one_sand' (代表所有人都吃得到)：
    回傳 0

// 步驟三：開始模擬發放過程
初始化 計數器 'vaild' 為 0
當 'vaild' < 'sandwiche_q' 的長度 時：
    如果 'student_q' 的最前面 == 'sandwiche_q' 的最前面：
        將 'student_q' 最前面的人彈出 (Pop)
        將 'sandwiche_q' 最前面的三明治彈出 (Pop)
        重置 'vaild' 為 0
    否則：
        將 'student_q' 最前面的人推入 (Push) 隊伍尾端
        將 'student_q' 最前面的人彈出 (Pop)
        'vaild' 加 1

// 步驟四：回傳結果
回傳 'student_q' 剩下的長度
```
</details>

## 複雜度分析

| Feature | Complexity |
| :--- | :--- |
| Time Complexity | $O(N^2)$ in the worst case (where N is the number of students). If the top sandwich is rejected multiple times, the queue will cycle repeatedly, pushing students to the back. |
| Space Complexity | $O(N)$ due to the extra memory used by `student_q` and `sandwiche_q` to store the initial data. |

<details>
<summary><b>點擊查看中文版</b></summary>

| 特性 | 複雜度 |
| :--- | :--- |
| 時間複雜度 | 最差情況為 $O(N^2)$ (N 為學生人數)。如果最上面的三明治一直被拒絕，隊伍會不斷把人推回尾端，導致大量的重複循環操作。 |
| 空間複雜度 | $O(N)$，因為額外宣告了 `student_q` 和 `sandwiche_q` 兩個佇列來模擬排隊與三明治堆疊。 |

</details>