#include <vector>
#include <optional>

bool isSameTree(TreeNode* p, TreeNode* q);

int main() {
    Tests.bool_check("Example 1",
        isSameTree(ints_to_tree({1, 2, 3}), ints_to_tree({1, 2, 3})) == true);

    Tests.bool_check("Example 2",
        isSameTree(ints_to_tree({4, 7}), list_to_tree({4, std::nullopt, 7})) == false);

    Tests.bool_check("Example 3",
        isSameTree(ints_to_tree({1, 2, 3}), ints_to_tree({1, 3, 2})) == false);

    return 0;
}
