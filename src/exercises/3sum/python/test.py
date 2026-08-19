s = Solution()
Tests.equal_check("Example 1", [[-1, -1, 2], [-1, 0, 1]], s.threeSum([-4, -1, -1, 0, 1, 2]))
Tests.equal_check("Example 2", [], s.threeSum([0, 1, 1]))
