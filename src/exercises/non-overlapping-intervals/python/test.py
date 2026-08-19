s = Solution()
Tests.equal_check("Example 1", 1, s.eraseOverlapIntervals([[1, 2], [1, 4], [2, 4]]))
Tests.equal_check("Example 2", 0, s.eraseOverlapIntervals([[1, 2], [2, 4]]))
