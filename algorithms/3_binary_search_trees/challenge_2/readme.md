#Measuring Christmas Tree

Santa is giving christmas trees with only two lengths X and Y. He needs to make sure that the tree length is exactly X or Y and for doing so he has a measuring tape but it has strange distances, it starts with 0 and ends with L and in the middle it has some numbers that represent distances. To measure distance D with the tape there should be a pair of numbers on the tape V1 and V2 such that V2 - V1 = D. Your task is to determine what is the minimum number of additional distances you need to add to the tape so that they can be used to measure the distances x and y. You are allowed to use unordered_map and unordered_set if needed
*A perfect binary tree is a binary tree in which all interior nodes have two children and all leaves have the same depth or same level

**Input Format**

- The first line contains four positive space-separated integers N, L, X, Y — the number of distances on the measuring tape, the length of the measuring tape and the two allowed lengthes of the trees


- The second line contains a sequence of n integers a1, a2, ..., an (0 = a1 < a2 < ... < an = l), where ai shows the distance between number i from the origin

**Constraints**

- (2 ≤ n ≤ 105, 2 ≤ l ≤ 109, 1 ≤ x < y ≤ l)



**Output Format**

print a single non-negative integer v — the minimum number of distances that you need to add on the tape.


**Sample Input 0**
```
3 250 185 230

0 185 250
```
**Sample Output 0**
```
1
```

**Explanation 0**

In the first sample it is impossible to initially measure the distance of 230 centimeters. For that it is enough to add a 20 centimeter mark or a 230 centimeter mark.

**Sample Input 1**

```
4 250 185 230

0 20 185 250
```
**Sample Output 1**
```
0
```
