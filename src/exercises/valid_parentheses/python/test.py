s = Solution()
Tests.bool_check("Example 1", s.isValid("[]") == True)
Tests.bool_check("Example 2", s.isValid("([{}])") == True)
Tests.bool_check("Example 3", s.isValid("[(])") == False)
