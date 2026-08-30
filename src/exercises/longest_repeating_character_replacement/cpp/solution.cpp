#include <string>
#include <vector>
#include <algorithm>

int characterReplacement(const std::string& s, int k) {
    std::vector<int> count(26, 0);
    int l = 0;
    int maxf = 0;
    int res = 0;

    for (int r = 0; r < static_cast<int>(s.length()); ++r) {
        count[s[r] - 'A']++;
        maxf = std::max(maxf, count[s[r] - 'A']);

        if ((r - l + 1) - maxf > k) {
            count[s[l] - 'A']--;
            l++;
        }
        res = std::max(res, r - l + 1);
    }
    return res;
}
