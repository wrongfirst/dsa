Tests.equal_check("Example 1", [4, 7, 2, 9, 6, 3, 1], tree_to_list(invertTree(list_to_tree([4, 2, 7, 1, 3, 6, 9]))))
Tests.equal_check("Example 2", [2, 3, 1], tree_to_list(invertTree(list_to_tree([2, 1, 3]))))
Tests.equal_check("Example 3", [], tree_to_list(invertTree(list_to_tree([]))))
