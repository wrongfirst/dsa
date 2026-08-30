#include <vector>
#include <optional>

TreeNode* buildTree(const std::vector<int>& preorder, const std::vector<int>& inorder);

int main() {
    Tests.equal_check("Example 1",
        std::vector<std::optional<int>>{1, 2, 3, std::nullopt, std::nullopt, std::nullopt, 4},
        tree_to_list(buildTree({1, 2, 3, 4}, {2, 1, 3, 4})));

    Tests.equal_check("Example 2",
        std::vector<std::optional<int>>{1},
        tree_to_list(buildTree({1}, {1})));

    return 0;
}
