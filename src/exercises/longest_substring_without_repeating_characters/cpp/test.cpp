#include <string>

int lengthOfLongestSubstring(const std::string& s);

int main() {
    Tests.equal_check("Example 1", 3, lengthOfLongestSubstring("abcabcbb"));
    Tests.equal_check("Example 2", 1, lengthOfLongestSubstring("bbbbb"));
    Tests.equal_check("Example 3", 3, lengthOfLongestSubstring("pwwkew"));
    Tests.equal_check("Empty string", 0, lengthOfLongestSubstring(""));
    return 0;
}
