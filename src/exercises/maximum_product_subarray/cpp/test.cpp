#include <vector>

int maxProduct(const std::vector<int>& nums);

int main() {
    Tests.equal_check("Example 1", 8, maxProduct({2, 4, -3, 5}));
    Tests.equal_check("Example 2", 0, maxProduct({-3, 0, -2}));
    return 0;
}
