board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
Tests.bool_check("Example 1", exist(board, "ABCCED") == True)
Tests.bool_check("Example 2", exist(board, "SEE") == True)
Tests.bool_check("Example 3", exist(board, "ABCB") == False)
