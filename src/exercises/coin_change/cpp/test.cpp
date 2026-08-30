#include <vector>

int coinChange(const std::vector<int>& coins, int amount);

int main() {
    Tests.equal_check("Example 1", 3, coinChange({1, 2, 5}, 11));
    Tests.equal_check("Example 2", -1, coinChange({2}, 3));
    Tests.equal_check("Example 3", 0, coinChange({1}, 0));
    return 0;
}
