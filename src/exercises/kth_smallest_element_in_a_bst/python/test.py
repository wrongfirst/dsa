s = Solution()
Tests.equal_check("Example 1", 1, s.kthSmallest(list_to_tree([2, 1, 3]), 1))
Tests.equal_check("Example 2", 5, s.kthSmallest(list_to_tree([4, 3, 5, 2, None]), 4))
