# [Carrots](https://www.hackerrank.com/contests/cmpn302-s2022-hw1/challenges/carrots-1)

There are a Rabbit trying to collect the maximum number of carrots from a 3*3 grid that has: some cells containing carrots (positive cells), some cells containing more powerful rabbits that steal carrots (negative cells), and zero cells do not take or give carrots. In each jump, the rabbit can jump one step up, down, or in any of the four diagonals. The rabbit starts its journey from the top left cell and ends at the bottom left cell. The rabbit is forbidden to visit the same cell more than once in its journey. It is required to print the maximum number of carrots it can collect in its journey. Note: assume that if our rabbit has, for example, 5 carrots and passed by a cell of value -7, then the total carrots so far will be -2 (a negative number not zero) indicating that the two will be taken from it later.

**Input Format**

- 3 lines, each line represents a row and contains 3 numbers separated by spaces

**Constraints**

- cell values are from -1000 to 1000

**Output Format**

- one line containing the maximum number of carrots the rabbit can collect in its journey


**Sample Input 0**
```
5 -1 -6
7 8 -7
6 -9 -8
```

**Sample Output 0**

```
25
```

**Explanation 0**

the path: 5 > 7 > -1 > 8 > 6
