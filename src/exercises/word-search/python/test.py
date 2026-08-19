s = Solution()
board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
Tests.bool_check("Example 1", s.exist(board, "ABCCED") == True)
Tests.bool_check("Example 2", s.exist(board, "SEE") == True)
Tests.bool_check("Example 3", s.exist(board, "ABCB") == False)
