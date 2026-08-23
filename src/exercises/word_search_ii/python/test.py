Tests.equal_check("Example 1", sorted(["cat", "backend", "back"]), sorted(findWords([["a", "b", "c", "d"], ["s", "a", "a", "t"], ["a", "c", "k", "e"], ["a", "c", "d", "n"]], ["bat", "cat", "back", "backend", "stack"])))
Tests.equal_check("Example 2", [], findWords([["x", "o"], ["x", "o"]], ["xoxo"]))
