board := [][]byte{
	{'A', 'B', 'C', 'E'},
	{'S', 'F', 'C', 'S'},
	{'A', 'D', 'E', 'E'},
}
Tests.BoolCheck("Example 1", exist(board, "ABCCED") == true)
Tests.BoolCheck("Example 2", exist(board, "SEE") == true)
Tests.BoolCheck("Example 3", exist(board, "ABCB") == false)
