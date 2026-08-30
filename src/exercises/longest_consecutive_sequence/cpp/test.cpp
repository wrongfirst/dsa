#include <vector>

int longestConsecutive(const std::vector<int>& nums);

int main() {
    Tests.equal_check("Example 1", 4, longestConsecutive({2, 20, 4, 10, 3, 4, 5}));
    Tests.equal_check("Example 2", 7, longestConsecutive({0, 3, 2, 5, 4, 6, 1, 1}));
    Tests.equal_check("Empty vector", 0, longestConsecutive({}));
    return 0;
}
