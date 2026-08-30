#include <vector>

bool canJump(const std::vector<int>& nums) {
    int goal = static_cast<int>(nums.size()) - 1;

    for (int i = static_cast<int>(nums.size()) - 2; i >= 0; --i) {
        if (i + nums[i] >= goal) {
            goal = i;
        }
    }

    return goal == 0;
}
