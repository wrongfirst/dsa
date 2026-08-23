board1 := [][]byte{
	{'a', 'b', 'c', 'd'},
	{'s', 'a', 'a', 't'},
	{'a', 'c', 'k', 'e'},
	{'a', 'c', 'd', 'n'},
}
Tests.EqualCheck("Example 1", SortStrings([]string{"cat", "backend", "back"}), SortStrings(findWords(board1, []string{"bat", "cat", "back", "backend", "stack"})))

board2 := [][]byte{
	{'x', 'o'},
	{'x', 'o'},
}
Tests.EqualCheck("Example 2", []string{}, findWords(board2, []string{"xoxo"}))

