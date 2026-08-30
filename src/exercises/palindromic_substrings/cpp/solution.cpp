#include <string>

static int countPali(const std::string& s, int l, int r) {
    int count = 0;
    int n = s.length();
    while (l >= 0 && r < n && s[l] == s[r]) {
        count++;
        l--;
        r++;
    }
    return count;
}

int countSubstrings(const std::string& s) {
    int res = 0;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        res += countPali(s, i, i);
        res += countPali(s, i, i + 1);
    }
    return res;
}
