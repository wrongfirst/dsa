#include <vector>

std::vector<int> topKFrequent(const std::vector<int>& nums, int k);

int main() {
    Tests.unordered_equal_check("Example 1", std::vector<int>{2, 3}, topKFrequent({1, 2, 2, 3, 3, 3}, 2));
    Tests.unordered_equal_check("Example 2", std::vector<int>{7}, topKFrequent({7, 7}, 1));
    return 0;
}
