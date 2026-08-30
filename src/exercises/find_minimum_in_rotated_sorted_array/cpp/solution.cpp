#include <vector>
#include <algorithm>

int findMin(const std::vector<int>& nums) {
    int start = 0;
    int end = static_cast<int>(nums.size()) - 1;
    int curr_min = nums[0];

    while (start < end) {
        int mid = start + (end - start) / 2;
        curr_min = std::min(curr_min, nums[mid]);

        if (nums[mid] > nums[end]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return std::min(curr_min, nums[start]);
}
