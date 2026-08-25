Tests.equal_check("Example 1", normalize_nested([[2, 2, 5], [9]]), normalize_nested(combinationSum([2, 5, 6, 9], 9)))
Tests.equal_check("Example 2", normalize_nested([[3, 3, 3, 3, 4], [3, 3, 5, 5], [4, 4, 4, 4], [3, 4, 4, 5]]), normalize_nested(combinationSum([3, 4, 5], 16)))
Tests.equal_check("Example 3", [], combinationSum([3], 5))
