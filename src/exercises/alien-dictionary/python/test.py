s = Solution()
Tests.equal_check("Example 1", "zo", s.foreignDictionary(["z", "o"]))
Tests.equal_check("Example 2", "hernf", s.foreignDictionary(["hrn", "hrf", "er", "enn", "rfnn"]))
Tests.equal_check("Example 3", "", s.foreignDictionary(["abc", "ab"]))
