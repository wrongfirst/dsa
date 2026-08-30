#include <vector>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums);

int main() {
    std::vector<int> nums1 = {-4, -1, -1, 0, 1, 2};
    Tests.unordered_equal_check("Example 1",
        std::vector<std::vector<int>>{{-1, -1, 2}, {-1, 0, 1}},
        threeSum(nums1));

    std::vector<int> nums2 = {0, 1, 1};
    Tests.unordered_equal_check("Example 2",
        std::vector<std::vector<int>>{},
        threeSum(nums2));

    return 0;
}
