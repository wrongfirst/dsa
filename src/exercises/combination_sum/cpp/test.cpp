#include <vector>

std::vector<std::vector<int>> combinationSum(const std::vector<int>& nums, int target);

int main() {
    Tests.unordered_equal_check("Example 1",
        std::vector<std::vector<int>>{{2, 2, 5}, {9}},
        combinationSum({2, 5, 6, 9}, 9));

    Tests.unordered_equal_check("Example 2",
        std::vector<std::vector<int>>{{3, 3, 3, 3, 4}, {3, 3, 5, 5}, {4, 4, 4, 4}, {3, 4, 4, 5}},
        combinationSum({3, 4, 5}, 16));

    Tests.unordered_equal_check("Example 3",
        std::vector<std::vector<int>>{},
        combinationSum({3}, 5));

    return 0;
}
