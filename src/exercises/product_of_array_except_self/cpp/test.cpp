#include <vector>

std::vector<int> productExceptSelf(const std::vector<int>& nums);

int main() {
    Tests.equal_check("Example 1", std::vector<int>{48, 24, 12, 8}, productExceptSelf({1, 2, 4, 6}));
    Tests.equal_check("Example 2", std::vector<int>{0, -6, 0, 0, 0}, productExceptSelf({-1, 0, 1, 2, 3}));
    return 0;
}
