#include <vector>
#include <algorithm>

int coinChange(const std::vector<int>& coins, int amount) {
    std::vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int a = 1; a <= amount; ++a) {
        for (int c : coins) {
            if (a - c >= 0) {
                dp[a] = std::min(dp[a], 1 + dp[a - c]);
            }
        }
    }
    return dp[amount] != amount + 1 ? dp[amount] : -1;
}
