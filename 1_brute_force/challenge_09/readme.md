
# [Radix Count](https://www.hackerrank.com/contests/cmpn302-s2022-hw1/challenges/radix-count)

Given a specific radix K and a length N, it is required to generate each string of length N in which the value of each digit could be from 0 to K-1, such that the generated string matches the given counts of each K value. For example, if K is 3, then 3 counts will be given, indicating the desired count of value 0, value 1, and value 2 respectively in the generated strings. Print the matching strings in lexicographical order.


**Input Format**

- one line containing K and N separated by a space
- one line containing K numbers separated by a space, where each number represents the desired count of each value. Note: the sum of those numbers equals N (the number of digits).

**Constraints**

- K is from 2 to 5
- N is from 1 to 10
- the sum of all the counts will be N (the number of digits)

**Output Format**

- each matching string in a separate line in lexicographical order


**Sample Input 0**
```
3 4
2 0 2
```

**Sample Output 0**
```
0022
0202
0220
2002
2020
2200
```

**Explanation 0**

Note that: the count of digit value 0, 1, and 2 in each string is 2, 0, and 2 respectively.




