#include <string>
#include <vector>

std::string foreignDictionary(const std::vector<std::string>& words);

int main() {
    Tests.equal_check("Example 1", std::string("zo"), foreignDictionary({"z", "o"}));
    Tests.equal_check("Example 2", std::string("hernf"), foreignDictionary({"hrn", "hrf", "er", "enn", "rfnn"}));
    Tests.equal_check("Example 3", std::string(""), foreignDictionary({"abc", "ab"}));
    return 0;
}
