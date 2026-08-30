#include <vector>
#include <optional>

bool isSubtree(TreeNode* root, TreeNode* subRoot);

int main() {
    Tests.bool_check("Example 1",
        isSubtree(ints_to_tree({1, 2, 3, 4, 5}), ints_to_tree({2, 4, 5})) == true);

    Tests.bool_check("Example 2",
        isSubtree(list_to_tree({1, 2, 3, 4, 5, std::nullopt, std::nullopt, 6}), ints_to_tree({2, 4, 5})) == false);

    return 0;
}
