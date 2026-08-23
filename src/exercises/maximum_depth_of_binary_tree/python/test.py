s = Solution()
Tests.equal_check("Example 1", 3, s.maxDepth(list_to_tree([1, 2, 3, None, None, 4])))
Tests.equal_check("Example 2", 0, s.maxDepth(list_to_tree([])))
