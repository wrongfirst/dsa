#include <string>
#include <vector>

bool isAnagram(const std::string& s, const std::string& t) {
    if (s.length() != t.length()) {
        return false;
    }
    std::vector<int> count(26, 0);
    for (size_t i = 0; i < s.length(); ++i) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    for (int c : count) {
        if (c != 0) return false;
    }
    return true;
}
