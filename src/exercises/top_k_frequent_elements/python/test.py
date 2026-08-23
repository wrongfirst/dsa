s = Solution()
Tests.equal_check("Example 1", [2, 3], sorted(s.topKFrequent([1, 2, 2, 3, 3, 3], 2)))
Tests.equal_check("Example 2", [7], sorted(s.topKFrequent([7, 7], 1)))
