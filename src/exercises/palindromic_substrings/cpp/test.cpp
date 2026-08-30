#include <string>

int countSubstrings(const std::string& s);

int main() {
    Tests.equal_check("Example 1", 3, countSubstrings("abc"));
    Tests.equal_check("Example 2", 6, countSubstrings("aaa"));
    return 0;
}
