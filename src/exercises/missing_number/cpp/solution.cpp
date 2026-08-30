#include <vector>

int missingNumber(const std::vector<int>& nums) {
    int res = nums.size();
    for (size_t i = 0; i < nums.size(); ++i) {
        res += static_cast<int>(i) - nums[i];
    }
    return res;
}
