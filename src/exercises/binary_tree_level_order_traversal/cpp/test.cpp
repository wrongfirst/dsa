#include <vector>

std::vector<std::vector<int>> levelOrder(TreeNode* root);

int main() {
    Tests.equal_check("Example 1",
        std::vector<std::vector<int>>{{1}, {2, 3}, {4, 5, 6, 7}},
        levelOrder(ints_to_tree({1, 2, 3, 4, 5, 6, 7})));

    Tests.equal_check("Example 2",
        std::vector<std::vector<int>>{{1}},
        levelOrder(ints_to_tree({1})));

    Tests.equal_check("Example 3",
        std::vector<std::vector<int>>{},
        levelOrder(ints_to_tree({})));

    return 0;
}
