A **prefix tree** (also known as a trie) is a tree data structure used to efficiently store and retrieve keys in a set of strings. Some applications of this data structure include auto-complete and spell checker systems.

Implement the `PrefixTree` class:
* `PrefixTree()`: Initializes the prefix tree object.
* `insert(word)`: Inserts string `word` into the prefix tree.
* `search(word)`: Returns `true` if string `word` exists in the prefix tree (was previously inserted), and `false` otherwise.
* `startsWith(prefix)`: Returns `true` if any previously inserted string begins with prefix `prefix`, and `false` otherwise.

**Example 1:**

```
Input:
["PrefixTree", "insert", "dog", "search", "dog", "search", "do", "startsWith", "do", "insert", "do", "search", "do"]

Output:
[null, null, true, false, true, null, true]

Explanation:
PrefixTree prefixTree = PrefixTree()
prefixTree.insert("dog")
prefixTree.search("dog")    // return true
prefixTree.search("do")     // return false
prefixTree.startsWith("do") // return true
prefixTree.insert("do")
prefixTree.search("do")     // return true
```

**Constraints:**
* `1 <= word.length, prefix.length <= 1000`
* `word` and `prefix` are made up of lowercase English letters.


