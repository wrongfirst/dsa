s = Solution()
Tests.equal_check("Example 1", sorted(["cat", "backend", "back"]), sorted(s.findWords([["a", "b", "c", "d"], ["s", "a", "a", "t"], ["a", "c", "k", "e"], ["a", "c", "d", "n"]], ["bat", "cat", "back", "backend", "stack"])))
Tests.equal_check("Example 2", [], s.findWords([["x", "o"], ["x", "o"]], ["xoxo"]))
