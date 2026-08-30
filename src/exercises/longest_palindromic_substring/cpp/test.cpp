#include <string>

std::string longestPalindrome(const std::string& s);

int main() {
    Tests.equal_check("Example 1", std::string("aba"), longestPalindrome("ababd"));
    Tests.equal_check("Example 2", std::string("bb"), longestPalindrome("abbc"));
    Tests.equal_check("Single character", std::string("a"), longestPalindrome("a"));
    return 0;
}
