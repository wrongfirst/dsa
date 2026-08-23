s = Solution()
Tests.bool_check("Example 1", s.hasCycle(make_cycle([1, 2, 3, 4], 1)) == True)
Tests.bool_check("Example 2", s.hasCycle(make_cycle([1, 2], -1)) == False)

