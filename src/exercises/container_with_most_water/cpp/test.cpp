#include <vector>

int maxArea(const std::vector<int>& heights);

int main() {
    Tests.equal_check("Example 1", 36, maxArea({1, 7, 2, 5, 4, 7, 3, 6}));
    Tests.equal_check("Example 2", 4, maxArea({2, 2, 2}));
    return 0;
}
