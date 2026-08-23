s = Solution()
Tests.equal_check("Example 1", 3, s.coinChange([1, 2, 5], 11))
Tests.equal_check("Example 2", -1, s.coinChange([2], 3))
Tests.equal_check("Example 3", 0, s.coinChange([1], 0))
