Tests.bool_check("Example 1", hasCycle(make_cycle([1, 2, 3, 4], 1)) == True)
Tests.bool_check("Example 2", hasCycle(make_cycle([1, 2], -1)) == False)
