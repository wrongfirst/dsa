#include <string>

std::string longestPalindrome(const std::string& s) {
    int n = s.length();
    if (n == 0) return "";

    int start = 0;
    int max_len = 0;

    for (int i = 0; i < n; ++i) {
        // Odd length
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r]) {
            if (r - l + 1 > max_len) {
                start = l;
                max_len = r - l + 1;
            }
            l--;
            r++;
        }

        // Even length
        l = i;
        r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r]) {
            if (r - l + 1 > max_len) {
                start = l;
                max_len = r - l + 1;
            }
            l--;
            r++;
        }
    }

    return s.substr(start, max_len);
}
