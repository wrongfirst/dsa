#include <string>
#include <vector>
#include <algorithm>

int longestCommonSubsequence(const std::string& text1, const std::string& text2) {
    int m = text1.length();
    int n = text2.length();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            if (text1[i] == text2[j]) {
                dp[i][j] = 1 + dp[i + 1][j + 1];
            } else {
                dp[i][j] = std::max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }

    return dp[0][0];
}
