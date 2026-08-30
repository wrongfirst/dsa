#include <vector>

std::vector<int> spiralOrder(const std::vector<std::vector<int>>& matrix);

int main() {
    Tests.equal_check("Example 1",
        std::vector<int>{1, 2, 4, 3},
        spiralOrder({{1, 2}, {3, 4}}));

    Tests.equal_check("Example 2",
        std::vector<int>{1, 2, 3, 6, 9, 8, 7, 4, 5},
        spiralOrder({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}));

    Tests.equal_check("Example 3",
        std::vector<int>{1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7},
        spiralOrder({{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}));

    return 0;
}
