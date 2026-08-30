#include <climits>

static bool isValidBSTHelper(TreeNode* node, long long min_val, long long max_val) {
    if (node == nullptr) return true;
    if (node->val <= min_val || node->val >= max_val) return false;
    return isValidBSTHelper(node->left, min_val, node->val) &&
           isValidBSTHelper(node->right, node->val, max_val);
}

bool isValidBST(TreeNode* root) {
    return isValidBSTHelper(root, LLONG_MIN, LLONG_MAX);
}
