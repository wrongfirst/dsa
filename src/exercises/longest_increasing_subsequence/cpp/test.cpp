#include <vector>

int lengthOfLIS(const std::vector<int>& nums);

int main() {
    Tests.equal_check("Example 1", 4, lengthOfLIS({9, 1, 4, 2, 3, 3, 7}));
    Tests.equal_check("Example 2", 4, lengthOfLIS({0, 3, 1, 3, 2, 3}));
    Tests.equal_check("Single element", 1, lengthOfLIS({10}));
    return 0;
}
