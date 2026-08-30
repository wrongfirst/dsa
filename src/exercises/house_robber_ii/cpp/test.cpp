#include <vector>

int rob(const std::vector<int>& nums);

int main() {
    Tests.equal_check("Example 1", 4, rob({3, 4, 3}));
    Tests.equal_check("Example 2", 15, rob({2, 9, 8, 3, 6}));
    Tests.equal_check("Single house", 5, rob({5}));
    return 0;
}
