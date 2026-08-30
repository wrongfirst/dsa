#include <vector>
#include <functional>

std::vector<std::vector<int>> combinationSum(const std::vector<int>& nums, int target) {
    std::vector<std::vector<int>> res;
    std::vector<int> cur;

    std::function<void(size_t, int)> dfs = [&](size_t i, int total) {
        if (total == target) {
            res.push_back(cur);
            return;
        }
        if (i >= nums.size() || total > target) {
            return;
        }

        cur.push_back(nums[i]);
        dfs(i, total + nums[i]);
        cur.pop_back();
        dfs(i + 1, total);
    };

    dfs(0, 0);
    return res;
}
