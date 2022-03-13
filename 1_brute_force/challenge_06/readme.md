# [A Project Team](https://www.hackerrank.com/contests/cmpn302-s2022-lab1/challenges/a-project-team)

Given N student names, we want to form one project team of M students. It is required to print all possible combinations of students joining that team. You are given N unique characters representing the first character of each student name, It is required to print all possible combinations of strings of length M where each string contains the characters of its students. Strings should be printed in Lexicographic order, and the letters of the same string should be printed sorted too. Note: this problem is a combination problem not permutation (for example, team ABC and BAC are the same team).

**Input Format**

- one line containing N and M, space separated
- one line containing N unique characters, space separated

**Constraints**

- N is from 1 to 20
- M is from 1 to 8 
- N is larger than or equal M
- the given characters are unique

**Output Format**

- print each string in a separate line, and strings are sorted in lexigraphical order

**Sample Input 0**
```
4 3
D C A B 
```

**Sample Output 0**

```
ABC
ABD
ACD
BCD
```

**Explanation 0**

Note that there is only one string containing (A, B, C), which means that ABC and BAC are one. All strings are sorted and the letters in the same string are sorted too.

