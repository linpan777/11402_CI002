# UVa 100 - The 3n+1 Problem

## Problem Description
Brief description of the problen here [click to the problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=36)

## Learning Objectives
1. Learn about 3n+1 conjecture
2. Practice i/o in C++
3. loop logic

## Preliminary thinking
### variable reference
| 變數 | 意義 |
| :--- | :--- |
| `a` | input number 1 |
| `b` | input number 2 |
| `c` | core loop variable |
| `times` | core loop to caculate cycle length |
| `max` | every time to store max cycle lenth | 
### Algorithm logic
1. input a, b
2. for loop(a -> b)
3.      while loop(c != 1)
4.          ++times
5.          (the core algorithm of 3n+1)
6.      if(max < times)
7.          max = times
8. output

## Challenges
1. forget to reset the variable(eg. times/max)
2. due to my for loop, <kbd>a</kbd> should smaller than <kbd>b</kbd>, but I didn't check
3. core algorithm is wrong, The condition check for <kbd>c</kbd> should be placed after <kbd>time++</kbd>, instead of being the while loop condition.
4. Didn't understand the question, 