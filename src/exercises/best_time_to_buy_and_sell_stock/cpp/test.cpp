#include <vector>

int maxProfit(const std::vector<int>& prices);

int main() {
    Tests.equal_check("Example 1", 5, maxProfit({7, 1, 5, 3, 6, 4}));
    Tests.equal_check("Example 2", 0, maxProfit({7, 6, 4, 3, 1}));
    return 0;
}
