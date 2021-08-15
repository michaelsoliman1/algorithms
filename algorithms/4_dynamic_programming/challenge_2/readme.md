# Paint the blocks 

You have a number of consequent blocks adjacent to each other and every block of width 1 m and height h[i] meter, you need to re-paint these blocks with the minimum number of steps given that you have two options, either you paint the blocks vertically, so you will paint only one block in one step, or you paint 1 m of all blocks with no gaps horizontally, for example if you have 4 blocks of sizes 2 3 2 3 you can paint the first 2 m meter horizontally of the 4 blocks in 2 steps but for the last meter of the second and fourth block you will not be able to do it in one step as there is a gap in the middle so each one will be done independently.

Note: you can re-paint the blocks more than once

**Input Format**

- The first line contains integer n (1 ≤ n ≤ 5000) — the number of blocks. The second line contains n space-separated integers a1, a2, ..., an (1 ≤ ai ≤ 10^9).


**Constraints**

- (1 ≤ n ≤ 5000) (1 ≤ ai ≤ 10^9)

**Output Format**

- print in a single line the minimum number of steps needed to paint all the blocks


**Sample Input 0**
```
5
2 2 1 2 1
```
**Sample Output 0**
```
3
```
**Explanation 0**

you need to paint the blocks like that: the first step goes on height 1 horizontally along all the blocks. The second step goes on height 2 horizontally and paints the first and second blocks, and the third step (it can be horizontal and vertical) finishes painting the fourth block.

**Sample Input 1**
```
2
2 2
```
**Sample Output 1**
```
2
```
**Explanation 1**

paint the blocks with two steps, either two horizontal or two vertical strokes.




