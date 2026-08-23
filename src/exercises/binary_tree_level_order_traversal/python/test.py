Tests.equal_check("Example 1", [[1], [2, 3], [4, 5, 6, 7]], levelOrder(list_to_tree([1, 2, 3, 4, 5, 6, 7])))
Tests.equal_check("Example 2", [[1]], levelOrder(list_to_tree([1])))
Tests.equal_check("Example 3", [], levelOrder(list_to_tree([])))
