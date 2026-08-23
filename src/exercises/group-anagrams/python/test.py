s = Solution()
Tests.equal_check("Example 1", normalize_nested([["act", "cat"], ["pots", "tops", "stop"], ["hat"]]), normalize_nested(s.groupAnagrams(["act", "pots", "tops", "cat", "stop", "hat"])))
Tests.equal_check("Example 2", normalize_nested([["x"]]), normalize_nested(s.groupAnagrams(["x"])))

