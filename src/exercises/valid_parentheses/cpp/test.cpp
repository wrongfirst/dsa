#include <string>

bool isValid(const std::string& s);

int main() {
    Tests.bool_check("Example 1", isValid("[]") == true);
    Tests.bool_check("Example 2", isValid("([{}])") == true);
    Tests.bool_check("Example 3", isValid("[(])") == false);

    Tests.bool_check("Single open bracket", isValid("(") == false);
    Tests.bool_check("Single close bracket", isValid("]") == false);

    Tests.bool_check("Close then open", isValid(")(") == false);
    Tests.bool_check("Extra closing bracket", isValid("())") == false);

    Tests.bool_check("Unclosed trailing bracket", isValid("()(") == false);
    Tests.bool_check("Nested unclosed bracket", isValid("((())") == false);

    Tests.bool_check("Sequential pairs", isValid("()[]{}") == true);
    Tests.bool_check("Direct mismatch", isValid("(]") == false);

    Tests.bool_check("Deep nesting", isValid("{[({[]})]}") == true);
    return 0;
}
