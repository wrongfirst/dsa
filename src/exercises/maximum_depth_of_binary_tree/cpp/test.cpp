#include <vector>
#include <optional>

int maxDepth(TreeNode* root);

int main() {
    Tests.equal_check("Example 1", 3, maxDepth(list_to_tree({1, 2, 3, std::nullopt, std::nullopt, 4})));
    Tests.equal_check("Example 2", 0, maxDepth(list_to_tree({})));
    return 0;
}
