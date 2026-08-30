#include <vector>

int rob(const std::vector<int>& nums);

int main() {
    Tests.equal_check("Example 1", 4, rob({1, 1, 3, 3}));
    Tests.equal_check("Example 2", 16, rob({2, 9, 8, 3, 6}));
    return 0;
}
