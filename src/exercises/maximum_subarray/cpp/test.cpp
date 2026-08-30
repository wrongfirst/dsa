#include <vector>

int maxSubArray(const std::vector<int>& nums);

int main() {
    Tests.equal_check("Example 1", 8, maxSubArray({2, -3, 4, -2, 2, 1, -1, 4}));
    Tests.equal_check("Example 2", -1, maxSubArray({-1}));
    return 0;
}
