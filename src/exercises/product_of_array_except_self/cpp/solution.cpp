#include <vector>

std::vector<int> productExceptSelf(const std::vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return {};
    std::vector<int> res(n, 1);

    for (int i = 1; i < n; ++i) {
        res[i] = res[i - 1] * nums[i - 1];
    }
    int postfix = 1;
    for (int i = n - 1; i >= 0; --i) {
        res[i] *= postfix;
        postfix *= nums[i];
    }
    return res;
}
