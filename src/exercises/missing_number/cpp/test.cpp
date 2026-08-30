#include <vector>

int missingNumber(const std::vector<int>& nums);

int main() {
    Tests.equal_check("Example 1", 0, missingNumber({1, 2, 3}));
    Tests.equal_check("Example 2", 1, missingNumber({0, 2}));
    return 0;
}
