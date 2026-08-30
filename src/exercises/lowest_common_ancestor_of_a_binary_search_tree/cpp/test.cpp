#include <vector>
#include <optional>

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);

int main() {
    TreeNode* t = list_to_tree({5, 3, 8, 1, 4, 7, 9, std::nullopt, 2});
    TreeNode p1(3);
    TreeNode q1(8);
    Tests.equal_check("Example 1", 5, lowestCommonAncestor(t, &p1, &q1)->val);

    TreeNode p2(3);
    TreeNode q2(4);
    Tests.equal_check("Example 2", 3, lowestCommonAncestor(t, &p2, &q2)->val);

    return 0;
}
