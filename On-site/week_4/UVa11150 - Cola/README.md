# 11150 - Cola

## 題目URL -> [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=23&page=show_problem&problem=2091)

## Thinking

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