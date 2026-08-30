#include <vector>
#include <algorithm>

int maxProduct(const std::vector<int>& nums) {
    if (nums.empty()) return 0;
    int res = nums[0];
    int cur_min = 1, cur_max = 1;

    for (int n : nums) {
        int tmp = cur_max * n;
        cur_max = std::max({n * cur_max, n * cur_min, n});
        cur_min = std::min({tmp, n * cur_min, n});
        res = std::max(res, cur_max);
    }
    return res;
}
