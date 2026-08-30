#include <string>

bool isAnagram(const std::string& s, const std::string& t);

int main() {
    Tests.bool_check("Example 1", isAnagram("racecar", "carrace") == true);
    Tests.bool_check("Example 2", isAnagram("jar", "jam") == false);
    return 0;
}
