s = Solution()
Tests.equal_check("Example 1", [1, 2, 3, None, None, None, 4], tree_to_list(s.buildTree([1, 2, 3, 4], [2, 1, 3, 4])))
Tests.equal_check("Example 2", [1], tree_to_list(s.buildTree([1], [1])))
