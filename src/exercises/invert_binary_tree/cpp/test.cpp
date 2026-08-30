#include <vector>
#include <optional>

TreeNode* invertTree(TreeNode* root);

int main() {
    Tests.equal_check("Example 1",
        std::vector<std::optional<int>>{4, 7, 2, 9, 6, 3, 1},
        tree_to_list(invertTree(list_to_tree({4, 2, 7, 1, 3, 6, 9}))));

    Tests.equal_check("Example 2",
        std::vector<std::optional<int>>{2, 3, 1},
        tree_to_list(invertTree(list_to_tree({2, 1, 3}))));

    Tests.equal_check("Example 3",
        std::vector<std::optional<int>>{},
        tree_to_list(invertTree(list_to_tree({}))));

    return 0;
}
