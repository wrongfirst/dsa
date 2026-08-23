Tests.bool_check("Example 1", isSubtree(list_to_tree([1, 2, 3, 4, 5]), list_to_tree([2, 4, 5])) == True)
Tests.bool_check("Example 2", isSubtree(list_to_tree([1, 2, 3, 4, 5, None, None, 6]), list_to_tree([2, 4, 5])) == False)
