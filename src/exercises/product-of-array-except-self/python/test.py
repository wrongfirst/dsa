s = Solution()
Tests.equal_check("Example 1", [48, 24, 12, 8], s.productExceptSelf([1, 2, 4, 6]))
Tests.equal_check("Example 2", [0, -6, 0, 0, 0], s.productExceptSelf([-1, 0, 1, 2, 3]))
