#include <vector>

int findMin(const std::vector<int>& nums);

int main() {
    Tests.equal_check("Example 1", 1, findMin({3, 4, 5, 6, 1, 2}));
    Tests.equal_check("Example 2", 0, findMin({4, 5, 0, 1, 2, 3}));
    Tests.equal_check("Single element", 5, findMin({5}));
    return 0;
}
