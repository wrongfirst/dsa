#include <string>
#include <vector>

std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& strs);

int main() {
    Tests.unordered_equal_check("Example 1",
        std::vector<std::vector<std::string>>{{"act", "cat"}, {"hat"}, {"pots", "stop", "tops"}},
        groupAnagrams({"act", "pots", "tops", "cat", "stop", "hat"}));

    Tests.unordered_equal_check("Example 2",
        std::vector<std::vector<std::string>>{{"x"}},
        groupAnagrams({"x"}));

    Tests.unordered_equal_check("Example 3",
        std::vector<std::vector<std::string>>{{""}},
        groupAnagrams({""}));
    return 0;
}
