# 11150 - Cola

## 題目URL -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=23&page=show_problem&problem=2091)

## Introduction:
The core of this problem is a "mathematical simulation" or "exchange mechanism." Given an initial number of cola bottles purchased, we need to calculate the total number of colas that can be consumed by repeatedly exchanging empty bottles for new colas. 
1. According to the problem's "borrowing rule," 2 empty bottles can be exchanged for 1 new cola. Therefore, the total colas consumed equals the initial bottles plus the number obtained through unlimited exchanges.

<details>
<summary><head>點擊查看中文版</head></summary>

核心是「數學模擬」、「兌換機制」。給定初始購買的可樂數量，需要計算透過不斷用空瓶兌換新可樂，最終能喝到的總數量。
1. 根據題目的「借空瓶規則」，每 2 個空瓶可以兌換 1 瓶新可樂，因此總消費量 = 初始購買數量 + 不斷極限兌換所得。

> **一句話筆記：初始 n 瓶可樂，2 個空瓶換 1 瓶新的，最終能喝 n + n/2 瓶。**
</details>

### variable reference:
| variable | meaning |
| :--- | :--- |
| `n` | Stores the large input integer as a string |
| `bottle` | The sum of digits at odd positions |

## 邏輯:
```text
1. while input n:
2.      Under the "borrowing" rule, the actual cost of 1 new cola is exactly 2 empty bottles.
3.      Total colas enjoyed = n (base colas) + n / 2 (extra colas exchanged from empty bottles).
4.      print n + n / 2. 
```

<details>
<summary><head>點擊查看中文版</head></summary>

```text
1. 當持續輸入 n (初始購買數量):
2.      根據「借空瓶」的極限規則，每消耗 2 個空瓶就能換到 1 瓶新可樂 (真實成本為 2 換 1)。
3.      總共能喝到的數量 = 保底喝掉的 n 瓶 + 拿 n 個空瓶去極限兌換的 (n / 2) 瓶。
4.      輸出 n + n / 2。
```

> [!Note]
>* 註：C++ 的整數除法會自動「無條件捨去」小數點，完美符合現實中湊不滿 2 個空瓶就換不到半瓶可樂的物理限制。
</details>