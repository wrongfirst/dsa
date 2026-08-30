static bool isSameTreeHelper(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) return true;
    if (p == nullptr || q == nullptr || p->val != q->val) return false;
    return isSameTreeHelper(p->left, q->left) && isSameTreeHelper(p->right, q->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (subRoot == nullptr) return true;
    if (root == nullptr) return false;

    if (isSameTreeHelper(root, subRoot)) {
        return true;
    }
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
