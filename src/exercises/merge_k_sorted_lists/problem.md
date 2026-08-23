You are given an array of `k` linked lists `lists`, where each list is sorted in ascending order.

Return the **sorted** linked list that is the result of merging all of the individual linked lists.

**Example 1:**

```java
Input: lists = [[1,2,4],[1,3,5],[3,6]]

Output: [1,1,2,3,3,4,5,6]
```

**Example 2:**

```java
Input: lists = []

Output: []
```

**Example 3:**

```java
Input: lists = [[]]

Output: []
```

**Constraints:**
* `0 <= lists.length <= 10000`
* `0 <= lists[i].length <= 500`
* `-10000 <= lists[i][j] <= 10000`
* `lists[i]` is sorted in **ascending** order.
* The sum of `lists[i].length` will not exceed `10000`.


<br>
