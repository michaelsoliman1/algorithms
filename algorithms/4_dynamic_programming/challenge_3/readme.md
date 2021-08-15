# Maximum sum 

Given an array of n integers you are required to partition this array to k partitions every partition has m consequent numbers such that the summation of these m*k numbers is maximum possible, note that the partitions should not overlap

**Input Format**

- The first line contains three integers n, m and k (1 ≤ (m × k) ≤ n ≤ 5000). The second line contains n integers p1, p2, ..., pn (0 ≤ p[i] ≤ 10^9).

**Output Format**

- a single line — the maximum possible value of sum.


**Sample Input 0**
```
5 2 1
1 2 3 4 5
```
**Sample Output 0**
```
9
```
**Explanation 0**

here we need to partition the array into k = 1 partition, and the partition has to have 2 numbers, so the partitions we have here is from index 1 to 2 -> sum = 3 from index 2 to 3 -> sum = 5 from index 3 to 4 -> sum = 7 from index 4 to 5 -> sum = 9

so the maximum sum is 9 for the last partition
**Sample Input 1**
```
7 1 3
2 10 7 18 5 33 0
```
**Sample Output 1**
```
61
```
**Explanation 1**

here we need to select 3 partitions with 1 number, so we can select the three maximum numbers of the array 33 + 18 + 10 = 61



