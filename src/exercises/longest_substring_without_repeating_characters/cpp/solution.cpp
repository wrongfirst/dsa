#include <string>
#include <unordered_set>
#include <algorithm>

int lengthOfLongestSubstring(const std::string& s) {
    std::unordered_set<char> char_set;
    int l = 0;
    int res = 0;

    for (int r = 0; r < static_cast<int>(s.length()); ++r) {
        while (char_set.find(s[r]) != char_set.end()) {
            char_set.erase(s[l]);
            l++;
        }
        char_set.insert(s[r]);
        res = std::max(res, r - l + 1);
    }
    return res;
}
