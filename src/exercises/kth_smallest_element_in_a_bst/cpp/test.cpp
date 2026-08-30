#include <vector>
#include <optional>

int kthSmallest(TreeNode* root, int k);

int main() {
    Tests.equal_check("Example 1", 1, kthSmallest(ints_to_tree({2, 1, 3}), 1));
    Tests.equal_check("Example 2", 5, kthSmallest(list_to_tree({4, 3, 5, 2, std::nullopt}), 4));
    return 0;
}
