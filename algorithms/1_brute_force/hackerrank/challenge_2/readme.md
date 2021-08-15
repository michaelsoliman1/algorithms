# [Treasure Cave 1](https://www.hackerrank.com/contests/cmpn302-fall2021-hw1/challenges/treasure-cave-1)

Your team have stumbled upon a cave full of treasures, 
you have equipment that can hold up to a maximum weight W. 
The cave has a set of items each with a weight and a value. 
You can choose to take whichever items under the condition 
that the sum of weights of the chosen items is less than the maximum weight W. 
You are required to find the maximum total value with weight less than or equal to 
the given limit W. You are required to answer the question above using brute force 
implemented using recursion.

**Input Format**

- The first line will contain the limit W.
- The second line will contain the number of items N.  
- The next N lines will contain an item each. 
  Each line will contain two space-separated numbers 
  representing the weight and the value of the item respectively.

**Constraints**

- Each item can be chosen once.
- Number of items can be from 0 to 25.
- W is between 1 and 10000 
- Each item weight and value is between 1 and 10000

**Output Format**

- One number indicating the maximum value.

**Sample Input 0**
```
14
5
2 2
12 4
1 1
1 2
4 10
```

**Sample Output 0**

```
15
```

**Explanation 0**

Items taken are items (0, 2, 3, 4) with value 15 and weight of 6.

**Sample Input 1**
```
10
4
7 3
1 2
4 2
6 6
```

**Sample Output 1**

```
8
```

**Explanation 1**

Items taken are items (1, 3) with value 8 and weight of 7.