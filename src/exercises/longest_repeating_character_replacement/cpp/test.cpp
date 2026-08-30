#include <string>

int characterReplacement(const std::string& s, int k);

int main() {
    Tests.equal_check("Example 1", 4, characterReplacement("XYYX", 2));
    Tests.equal_check("Example 2", 5, characterReplacement("AAABABB", 1));
    return 0;
}
