#include <stack>

int kthSmallest(TreeNode* root, int k) {
    std::stack<TreeNode*> st;
    TreeNode* curr = root;

    while (!st.empty() || curr != nullptr) {
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        k--;
        if (k == 0) {
            return curr->val;
        }
        curr = curr->right;
    }
    return -1;
}
