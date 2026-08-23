board1 = [
    ["A", "B", "C", "D"],
    ["S", "A", "A", "T"],
    ["A", "C", "A", "E"]
]
Tests.bool_check("Example 1", exist(board1, "CAT") == True)

board2 = [
    ["A", "B", "C", "D"],
    ["S", "A", "A", "T"],
    ["A", "C", "A", "E"]
]
Tests.bool_check("Example 2", exist(board2, "BAT") == False)
