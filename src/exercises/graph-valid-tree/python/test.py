s = Solution()
Tests.bool_check("Example 1", s.validTree(5, [[0, 1], [0, 2], [0, 3], [1, 4]]) == True)
Tests.bool_check("Example 2", s.validTree(5, [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]]) == False)
