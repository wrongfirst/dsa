#include <vector>

bool hasDuplicate(const std::vector<int>& nums);

int main() {
    Tests.bool_check("Example 1", hasDuplicate({1, 2, 3, 3}) == true);
    Tests.bool_check("Example 2", hasDuplicate({1, 2, 3, 4}) == false);
    return 0;
}
