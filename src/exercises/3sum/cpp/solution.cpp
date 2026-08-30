#include <vector>
#include <algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> res;
    std::sort(nums.begin(), nums.end());

    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        if (nums[i] > 0) break;
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int l = i + 1;
        int r = n - 1;
        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum > 0) {
                r--;
            } else if (sum < 0) {
                l++;
            } else {
                res.push_back({nums[i], nums[l], nums[r]});
                l++;
                r--;
                while (l < r && nums[l] == nums[l - 1]) {
                    l++;
                }
            }
        }
    }
    return res;
}
