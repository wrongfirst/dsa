def normalize(groups):
    return sorted([sorted(g) for g in groups])

s = Solution()
Tests.equal_check("Example 1", normalize([["act", "cat"], ["pots", "tops", "stop"], ["hat"]]), normalize(s.groupAnagrams(["act", "pots", "tops", "cat", "stop", "hat"])))
Tests.equal_check("Example 2", normalize([["x"]]), normalize(s.groupAnagrams(["x"])))
