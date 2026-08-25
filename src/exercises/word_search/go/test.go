board1 := [][]byte{
	{'A', 'B', 'C', 'D'},
	{'S', 'A', 'A', 'T'},
	{'A', 'C', 'A', 'E'},
}
Tests.BoolCheck("Example 1", exist(board1, "CAT") == true)

board2 := [][]byte{
	{'A', 'B', 'C', 'D'},
	{'S', 'A', 'A', 'T'},
	{'A', 'C', 'A', 'E'},
}
Tests.BoolCheck("Example 2", exist(board2, "BAT") == false)
