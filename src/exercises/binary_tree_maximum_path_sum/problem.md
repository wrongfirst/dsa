Given the `root` of a *non-empty* binary tree, return the maximum **path sum** of any *non-empty* path.

A **path** in a binary tree is a sequence of nodes where each pair of adjacent nodes has an edge connecting them. A node can *not* appear in the sequence more than once. The path does *not* necessarily need to include the root.

The **path sum** of a path is the sum of the node's values in the path.

**Example 1:**

![](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/9896b041-9021-44c2-ab3e-5cff76adf100/public)

```java
Input: root = [1,2,3]

Output: 6
```

Explanation: The path is 2 -> 1 -> 3 with a sum of 2 + 1 + 3 = 6.

**Example 2:**

![](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/19ce1187-387e-4323-f2c9-1a317ab36200/public)

```java
Input: root = [-15,10,20,null,null,15,5,-5]

Output: 40
```

Explanation: The path is 15 -> 20 -> 5 with a sum of 15 + 20 + 5 = 40.

**Constraints:**
* `1 <= The number of nodes in the tree <= 30000`.
* `-1000 <= Node.val <= 1000`


