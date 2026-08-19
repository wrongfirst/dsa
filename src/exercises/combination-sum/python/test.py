def normalize(groups):
    return sorted([sorted(g) for g in groups])

s = Solution()
Tests.equal_check("Example 1", normalize([[2, 2, 5], [9]]), normalize(s.combinationSum([2, 5, 6, 9], 9)))
Tests.equal_check("Example 2", normalize([[3, 3, 3, 3, 4], [3, 3, 5, 5], [4, 4, 4, 4], [3, 4, 4, 5]]), normalize(s.combinationSum([3, 4, 5], 16)))
Tests.equal_check("Example 3", [], s.combinationSum([3], 5))
