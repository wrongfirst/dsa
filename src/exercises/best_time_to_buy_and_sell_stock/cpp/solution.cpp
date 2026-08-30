#include <vector>
#include <algorithm>

int maxProfit(const std::vector<int>& prices) {
    if (prices.empty()) return 0;
    int res = 0;
    int lowest = prices[0];

    for (int price : prices) {
        if (price < lowest) {
            lowest = price;
        }
        res = std::max(res, price - lowest);
    }
    return res;
}
