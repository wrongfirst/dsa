s = Solution()
Tests.equal_check("Example 1", ["Hello", "World"], s.decode(s.encode(["Hello", "World"])))
Tests.equal_check("Example 2", [""], s.decode(s.encode([""])))
