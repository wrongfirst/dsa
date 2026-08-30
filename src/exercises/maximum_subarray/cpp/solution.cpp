#include <vector>
#include <algorithm>

int maxSubArray(const std::vector<int>& nums) {
    if (nums.empty()) return 0;
    int res = nums[0];
    int total = 0;

    for (int n : nums) {
        total += n;
        res = std::max(res, total);
        if (total < 0) {
            total = 0;
        }
    }
    return res;
}
