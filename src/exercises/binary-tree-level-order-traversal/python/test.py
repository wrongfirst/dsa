s = Solution()
Tests.equal_check("Example 1", [[1], [2, 3], [4, 5, 6, 7]], s.levelOrder(list_to_tree([1, 2, 3, 4, 5, 6, 7])))
Tests.equal_check("Example 2", [[1]], s.levelOrder(list_to_tree([1])))
Tests.equal_check("Example 3", [], s.levelOrder(list_to_tree([])))
