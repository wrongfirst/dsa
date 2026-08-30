#include <string>

bool isPalindrome(const std::string& s);

int main() {
    Tests.bool_check("Example 1", isPalindrome("Was it a car or a cat I saw?") == true);
    Tests.bool_check("Example 2", isPalindrome("tab a cat") == false);
    Tests.bool_check("Empty string", isPalindrome("") == true);
    return 0;
}
