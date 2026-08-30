#include <vector>

bool isValidBST(TreeNode* root);

int main() {
    Tests.bool_check("Example 1", isValidBST(ints_to_tree({2, 1, 3})) == true);
    Tests.bool_check("Example 2", isValidBST(ints_to_tree({1, 2, 3})) == false);
    Tests.bool_check("Empty tree", isValidBST(nullptr) == true);
    return 0;
}
