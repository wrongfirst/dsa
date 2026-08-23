s = Solution()
Tests.equal_check("Example 1", "YXAZ", s.minWindow("OUZODYXAZV", "XYZ"))
Tests.equal_check("Example 2", "xyz", s.minWindow("xyz", "xyz"))
Tests.equal_check("Example 3", "", s.minWindow("x", "xy"))
