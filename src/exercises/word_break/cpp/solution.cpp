#include <string>
#include <vector>

bool wordBreak(const std::string& s, const std::vector<std::string>& wordDict) {
    int n = s.length();
    std::vector<bool> dp(n + 1, false);
    dp[n] = true;

    for (int i = n - 1; i >= 0; --i) {
        for (const auto& w : wordDict) {
            int w_len = w.length();
            if (i + w_len <= n && s.substr(i, w_len) == w) {
                if (dp[i + w_len]) {
                    dp[i] = true;
                    break;
                }
            }
        }
    }

    return dp[0];
}
