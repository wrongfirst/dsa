Tests.bool_check("Example 1", isSameTree(list_to_tree([1, 2, 3]), list_to_tree([1, 2, 3])) == True)
Tests.bool_check("Example 2", isSameTree(list_to_tree([4, 7]), list_to_tree([4, None, 7])) == False)
Tests.bool_check("Example 3", isSameTree(list_to_tree([1, 2, 3]), list_to_tree([1, 3, 2])) == False)
