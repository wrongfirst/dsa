# Problem examples
Tests.bool_check("Example 1", isValid("[]") == True)
Tests.bool_check("Example 2", isValid("([{}])") == True)
Tests.bool_check("Example 3", isValid("[(])") == False)

# Single character / Odd length
Tests.bool_check("Single open bracket", isValid("(") == False)
Tests.bool_check("Single close bracket", isValid("]") == False)

# Stack underflow / Leading closing brackets
Tests.bool_check("Close then open", isValid(")(") == False)
Tests.bool_check("Extra closing bracket", isValid("())") == False)

# Incomplete / Unclosed brackets
Tests.bool_check("Unclosed trailing bracket", isValid("()(") == False)
Tests.bool_check("Nested unclosed bracket", isValid("((())") == False)

# Sequential & direct mismatch
Tests.bool_check("Sequential pairs", isValid("()[]{}") == True)
Tests.bool_check("Direct mismatch", isValid("(]") == False)

# Deep nesting & boundary limits
Tests.bool_check("Deep nesting", isValid("{[({[]})]}") == True)
Tests.bool_check("Max length valid", isValid("()" * 500) == True)
Tests.bool_check("Max length unclosed", isValid("(" * 1000) == False)
