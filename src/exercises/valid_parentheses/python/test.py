Tests.bool_check("Example 1", isValid("[]") == True)
Tests.bool_check("Example 2", isValid("([{}])") == True)
Tests.bool_check("Example 3", isValid("[(])") == False)
