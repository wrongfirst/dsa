#include <vector>
#include <unordered_map>
#include <functional>

TreeNode* buildTree(const std::vector<int>& preorder, const std::vector<int>& inorder) {
    std::unordered_map<int, int> indices;
    for (int i = 0; i < static_cast<int>(inorder.size()); ++i) {
        indices[inorder[i]] = i;
    }

    int pre_idx = 0;
    std::function<TreeNode*(int, int)> dfs = [&](int l, int r) -> TreeNode* {
        if (l > r) return nullptr;

        int root_val = preorder[pre_idx++];
        TreeNode* root = new TreeNode(root_val);
        int mid = indices[root_val];

        root->left = dfs(l, mid - 1);
        root->right = dfs(mid + 1, r);
        return root;
    };

    return dfs(0, static_cast<int>(inorder.size()) - 1);
}
