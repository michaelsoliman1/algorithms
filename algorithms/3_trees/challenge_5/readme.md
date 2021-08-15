# [Dark streets](https://www.hackerrank.com/contests/cmpn302-fall2021-lab4/challenges/dark-streets)

Bob fears the dark and unfortunately many streetlights in his neighborhood are broken. He wants to visit some of his friend today as he feels so lonely, so he needs some help. The streets are represented as a tree with root at node 1 and N Nodes, the leaves of the tree contains his friends. He needs to know which friend he can visit given that he can't take a path that have more than M consecutive dark streets. Count the number of friends he can visit.

**Notes** : The tree is not binary, so the node may have multiple children, also it is not guaranteed that the edges will be given from parent to child so if node B has a parent A, the edge in the input could be B A or A B


**Input Format**

- The first line contains two integers, N and M — the number of nodes of the tree, and the maximum number of consecutive dark nodes

- The second line contains n numbers either equals to 1 if the node is dark, or 0 otherwise.

- Next n - 1 lines contains the edges of the tree in the format "xi yi" (without the quotes) (1 ≤ xi, yi ≤ n, xi ≠ yi), where xi and yi are the nodes of the tree, connected by an edge.

- It is guaranteed that the given set of edges specifies a tree.


**Constraints**

- (2 ≤ n ≤ 10^5, 1 ≤ m ≤ n)

**Output Format**

The number of distinct leaves of the tree with a valid path

**Sample Input 0**
```
4 1
1 1 0 0
1 2
1 3
1 4
```
**Sample Output 0**
```
2
```
**Sample Input 1**
```
7 1
1 0 1 1 0 0 0
1 2
1 3
2 4
2 5
3 6
3 7
```
**Sample Output 1**
```
2
```


