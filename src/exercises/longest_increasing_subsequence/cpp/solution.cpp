#include <vector>
#include <algorithm>

int lengthOfLIS(const std::vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    std::vector<int> lis(n, 1);
    int max_len = 1;

    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums[i] < nums[j]) {
                lis[i] = std::max(lis[i], 1 + lis[j]);
            }
        }
        max_len = std::max(max_len, lis[i]);
    }
    return max_len;
}
