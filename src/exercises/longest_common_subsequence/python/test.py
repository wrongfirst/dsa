s = Solution()
Tests.equal_check("Example 1", 3, s.longestCommonSubsequence("crabt", "cat"))
Tests.equal_check("Example 2", 4, s.longestCommonSubsequence("abcd", "abcd"))
Tests.equal_check("Example 3", 0, s.longestCommonSubsequence("abcd", "efgh"))
