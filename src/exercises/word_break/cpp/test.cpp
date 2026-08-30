#include <string>
#include <vector>

bool wordBreak(const std::string& s, const std::vector<std::string>& wordDict);

int main() {
    Tests.bool_check("Example 1", wordBreak("neetcode", {"neet", "code"}) == true);
    Tests.bool_check("Example 2", wordBreak("applepenapple", {"apple", "pen", "ape"}) == true);
    Tests.bool_check("Example 3", wordBreak("catsandog", {"cats", "dog", "sand", "and", "cat"}) == false);
    return 0;
}
