# [Coin Game 6](https://www.hackerrank.com/contests/cmpn302-fall2021-lab1/challenges/coin-game-6)

You are playing a game and you are given a collection of coins of size N where each coin has a value in pounds as an array of positive integers A [0...N-1]. You find a mission that requires you to collect exactly a total value of T pounds. Is it possible to take coins from A that sums to exactly T? You are required to answer the question above using non-optimized brute force solution.

**Input Format**

- The first line will contain T.
- The second line will contain N, denoting the number of integers in the array A.
- Each of the next N lines will contain an integer to build the array A.

**Constraints**

- Each coin A[i] can be taken once.
- Range of N is from 1 to 25.
- T value can be 0.

**Output Format**

- 1 if you can choose coins that sums to exactly T and 0 if you cannot.

**Sample Input 0**
```
10
4
2
1
5
1
```

**Sample Output 0**

```
0
```

**Sample Input 1**
```
10
3
5
2
3
```

**Sample Output 1**

```
1
```