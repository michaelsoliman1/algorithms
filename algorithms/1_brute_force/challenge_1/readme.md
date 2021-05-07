#Boss Lair

You are a hero entering a boss’s lair. The consists of N floors. Each _floor is square shaped and consists of multiple square-shaped rooms of similar size. Each _floor has N rows by N columns of rooms. From each room, you can access the same room in the _floor above, and the rooms to your right, and bottom directions. Upon entering each room, you pay a certain amount of gold. You enter from the lowest _floor from the room to the top left. The boss is at the highest _floor in the room to the bottom right. Given the amount paid for each room, find the minimum amount of gold needed to reach the boss’s room. You are required to answer the question above using brute force implemented using recursion.

**Input Format**

- The first line will contain N.
- The next N lines will contain N numbers each denoting the gold required for each room in _floor 0 (lowest _floor). (Hint: you can input these numbers using cin normally. “cin >> var1 >> var2)
- For each remaining _floor the same format is repeated.

**Constraints**

- 1 <= N <= 7.
- Coins for each room is between 0 and 10000.
- You cannot visit a room twice

**Output Format**

- The minimum amount of gold required to reach the boss’s room.

**Sample Input 0**
```
2
10 15
12 13
25 8
2 3
```

**Sample Output 0**

```
27
```

**Explanation 0**

The path taken is (10, 12, 2, 3)