#include <vector>
#include <optional>

int maxPathSum(TreeNode* root);

int main() {
    Tests.equal_check("Example 1", 6, maxPathSum(ints_to_tree({1, 2, 3})));
    Tests.equal_check("Example 2", 40, maxPathSum(list_to_tree({-15, 10, 20, std::nullopt, std::nullopt, 15, 5, -5})));
    return 0;
}
