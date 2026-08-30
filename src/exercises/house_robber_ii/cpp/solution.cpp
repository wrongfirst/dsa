#include <vector>
#include <algorithm>

static int robSimple(const std::vector<int>& nums, int start, int end) {
    int rob1 = 0, rob2 = 0;
    for (int i = start; i <= end; ++i) {
        int temp = std::max(nums[i] + rob1, rob2);
        rob1 = rob2;
        rob2 = temp;
    }
    return rob2;
}

int rob(const std::vector<int>& nums) {
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];

    int n = nums.size();
    return std::max(robSimple(nums, 0, n - 2), robSimple(nums, 1, n - 1));
}
