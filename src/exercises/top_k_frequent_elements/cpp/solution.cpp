#include <vector>
#include <unordered_map>

std::vector<int> topKFrequent(const std::vector<int>& nums, int k) {
    std::unordered_map<int, int> count;
    for (int n : nums) {
        count[n]++;
    }

    std::vector<std::vector<int>> freq(nums.size() + 1);
    for (const auto& pair : count) {
        freq[pair.second].push_back(pair.first);
    }

    std::vector<int> res;
    for (int i = static_cast<int>(freq.size()) - 1; i >= 0; --i) {
        for (int n : freq[i]) {
            res.push_back(n);
            if (static_cast<int>(res.size()) == k) {
                return res;
            }
        }
    }
    return res;
}
