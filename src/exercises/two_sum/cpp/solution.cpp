#include <vector>
#include <unordered_map>

std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> prev_map;
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        int diff = target - nums[i];
        if (prev_map.find(diff) != prev_map.end()) {
            return {prev_map[diff], i};
        }
        prev_map[nums[i]] = i;
    }
    return {};
}
