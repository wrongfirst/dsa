#include <vector>

int search(const std::vector<int>& nums, int target);

int main() {
    Tests.equal_check("Example 1", 4, search({3, 4, 5, 6, 1, 2}, 1));
    Tests.equal_check("Example 2", -1, search({3, 5, 6, 0, 1, 2}, 4));
    return 0;
}
