#include <string>
#include <unordered_map>
#include <climits>

std::string minWindow(const std::string& s, const std::string& t) {
    if (t.empty() || s.empty()) return "";

    std::unordered_map<char, int> count_t;
    for (char c : t) {
        count_t[c]++;
    }

    std::unordered_map<char, int> window;
    int have = 0, need = static_cast<int>(count_t.size());
    int res_len = INT_MAX;
    int res_start = -1;
    int l = 0;

    for (int r = 0; r < static_cast<int>(s.length()); ++r) {
        char c = s[r];
        window[c]++;

        if (count_t.find(c) != count_t.end() && window[c] == count_t[c]) {
            have++;
        }

        while (have == need) {
            if ((r - l + 1) < res_len) {
                res_len = r - l + 1;
                res_start = l;
            }

            window[s[l]]--;
            if (count_t.find(s[l]) != count_t.end() && window[s[l]] < count_t[s[l]]) {
                have--;
            }
            l++;
        }
    }

    return res_len == INT_MAX ? "" : s.substr(res_start, res_len);
}
