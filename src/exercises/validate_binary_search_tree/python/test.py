s = Solution()
Tests.bool_check("Example 1", s.isValidBST(list_to_tree([2, 1, 3])) == True)
Tests.bool_check("Example 2", s.isValidBST(list_to_tree([1, 2, 3])) == False)
