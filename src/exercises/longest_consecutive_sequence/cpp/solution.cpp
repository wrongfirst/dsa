#include <vector>
#include <unordered_set>
#include <algorithm>

int longestConsecutive(const std::vector<int>& nums) {
    std::unordered_set<int> num_set(nums.begin(), nums.end());
    int longest = 0;

    for (int n : num_set) {
        if (num_set.find(n - 1) == num_set.end()) {
            int length = 1;
            while (num_set.find(n + length) != num_set.end()) {
                length++;
            }
            longest = std::max(longest, length);
        }
    }
    return longest;
}
