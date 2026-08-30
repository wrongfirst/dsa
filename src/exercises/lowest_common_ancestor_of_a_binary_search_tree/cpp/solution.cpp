TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* curr = root;
    while (curr != nullptr) {
        if (curr->val < p->val && curr->val < q->val) {
            curr = curr->right;
        } else if (curr->val > p->val && curr->val > q->val) {
            curr = curr->left;
        } else {
            return curr;
        }
    }
    return root;
}
