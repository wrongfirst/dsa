// Problem examples
Tests.BoolCheck("Example 1", isValid("[]") == true)
Tests.BoolCheck("Example 2", isValid("([{}])") == true)
Tests.BoolCheck("Example 3", isValid("[(])") == false)

// Single character / Odd length
Tests.BoolCheck("Single open bracket", isValid("(") == false)
Tests.BoolCheck("Single close bracket", isValid("]") == false)

// Stack underflow / Leading closing brackets
Tests.BoolCheck("Close then open", isValid(")(") == false)
Tests.BoolCheck("Extra closing bracket", isValid("())") == false)

// Incomplete / Unclosed brackets
Tests.BoolCheck("Unclosed trailing bracket", isValid("()(") == false)
Tests.BoolCheck("Nested unclosed bracket", isValid("((())") == false)

// Sequential & direct mismatch
Tests.BoolCheck("Sequential pairs", isValid("()[]{}") == true)
Tests.BoolCheck("Direct mismatch", isValid("(]") == false)

// Deep nesting & boundary limits
Tests.BoolCheck("Deep nesting", isValid("{[({[]})]}") == true)
Tests.BoolCheck("Max length valid", isValid(strings.Repeat("()", 500)) == true)
Tests.BoolCheck("Max length unclosed", isValid(strings.Repeat("(", 1000)) == false)
