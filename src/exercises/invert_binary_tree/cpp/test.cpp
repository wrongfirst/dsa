#include <vector>
#include <optional>

TreeNode* invertTree(TreeNode* root);

int main() {
    // Problem description examples
    Tests.equal_check("Problem Example 1",
        std::vector<std::optional<int>>{1, 3, 2, 7, 6, 5, 4},
        tree_to_list(invertTree(list_to_tree({1, 2, 3, 4, 5, 6, 7}))));

    Tests.equal_check("Problem Example 2",
        std::vector<std::optional<int>>{3, 1, 2},
        tree_to_list(invertTree(list_to_tree({3, 2, 1}))));

    // Single node
    Tests.equal_check("Single node",
        std::vector<std::optional<int>>{1},
        tree_to_list(invertTree(list_to_tree({1}))));

    // Asymmetric / Skewed trees
    Tests.equal_check("Left child only",
        std::vector<std::optional<int>>{1, std::nullopt, 2},
        tree_to_list(invertTree(list_to_tree({1, 2}))));

    Tests.equal_check("Right child only",
        std::vector<std::optional<int>>{1, 2},
        tree_to_list(invertTree(list_to_tree({1, std::nullopt, 2}))));

    Tests.equal_check("Left-skewed tree",
        std::vector<std::optional<int>>{1, std::nullopt, 2, std::nullopt, 3},
        tree_to_list(invertTree(list_to_tree({1, 2, std::nullopt, 3}))));

    Tests.equal_check("Right-skewed tree",
        std::vector<std::optional<int>>{1, 2, std::nullopt, 3},
        tree_to_list(invertTree(list_to_tree({1, std::nullopt, 2, std::nullopt, 3}))));

    // Negative and zero values
    Tests.equal_check("Negative values and bounds",
        std::vector<std::optional<int>>{0, 100, -100},
        tree_to_list(invertTree(list_to_tree({0, -100, 100}))));

    // Duplicate values
    Tests.equal_check("Duplicate values",
        std::vector<std::optional<int>>{2, 2, 2},
        tree_to_list(invertTree(list_to_tree({2, 2, 2}))));

    return 0;
}
