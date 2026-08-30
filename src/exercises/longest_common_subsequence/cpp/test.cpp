#include <string>

int longestCommonSubsequence(const std::string& text1, const std::string& text2);

int main() {
    Tests.equal_check("Example 1", 3, longestCommonSubsequence("crabt", "cat"));
    Tests.equal_check("Example 2", 4, longestCommonSubsequence("abcd", "abcd"));
    Tests.equal_check("Example 3", 0, longestCommonSubsequence("abcd", "efgh"));
    return 0;
}
