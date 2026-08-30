#include <vector>

bool canJump(const std::vector<int>& nums);

int main() {
    Tests.bool_check("Example 1", canJump({1, 2, 0, 1, 0}) == true);
    Tests.bool_check("Example 2", canJump({1, 2, 1, 0, 1}) == false);
    Tests.bool_check("Single element", canJump({0}) == true);
    return 0;
}
