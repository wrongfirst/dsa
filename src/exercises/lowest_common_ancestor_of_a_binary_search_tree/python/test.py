s = Solution()
t = list_to_tree([5, 3, 8, 1, 4, 7, 9, None, 2])
Tests.equal_check("Example 1", 5, s.lowestCommonAncestor(t, TreeNode(3), TreeNode(8)).val)
Tests.equal_check("Example 2", 3, s.lowestCommonAncestor(t, TreeNode(3), TreeNode(4)).val)
