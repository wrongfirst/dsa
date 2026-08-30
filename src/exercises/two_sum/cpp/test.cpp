#include <vector>

std::vector<int> twoSum(const std::vector<int>& nums, int target);

int main() {
    Tests.equal_check("Example 1", std::vector<int>{0, 1}, twoSum({3, 4, 5, 6}, 7));
    Tests.equal_check("Example 2", std::vector<int>{0, 2}, twoSum({4, 5, 6}, 10));
    return 0;
}
