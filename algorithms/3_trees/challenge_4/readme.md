# [Subtree Size](https://www.hackerrank.com/contests/cmpn302-fall2021-lab4/challenges/subtree-size)

Mike and Tanya are bored, so they decided to play a game, Mike will create a tree rooted at node 1 and give it to Tanya, and she has to answer two types of queries

type1- given a node on the tree she has to figure out the size of the node's subtree

type2- given a size x she has to count the number of subtrees that have size x

She will have to answer Q queries correctly to win, otherwise she will lose the game.

You are allowed to use unordered_map and unordered_set if needed


**Input Format**

- The first line contains n, number of nodes in the tree.

- Each of the next n lines contains two integers, a b, where a is the index of left child, and b is the index of right child of ith node.

- Note: -1 is used to represent a null node.

- The next line contains an integer q, the number of quires

- Each of the next q lines contains two integers, x,y where x is the query type and y is the node number or a size value

**Constraints**

- 1 <= n <= 10000

- a = -1 or 2 <= a <= n

- b = -1 or 2 <= b <= n

- 1 <= q <= 100000

- x= {1,2}

- 1 <= y <= 100000

**Output Format**

for each query output the result on a single line


**Sample Input 0**
```
3
2 3
-1 -1
-1 -1
2
1 1
2 1
```
**Sample Output 0**
```
3
2
```

**Sample Input 1**
```
5
2 3
-1 4
-1 5
-1 -1
-1 -1
4
1 1
1 5
1 2
2 5
```
**Sample Output 1**
```
5
1
2
1
```


