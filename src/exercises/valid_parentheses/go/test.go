Tests.BoolCheck("Example 1", isValid("[]") == true)
Tests.BoolCheck("Example 2", isValid("([{}])") == true)
Tests.BoolCheck("Example 3", isValid("[(])") == false)
