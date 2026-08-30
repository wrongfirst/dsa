#include <vector>
#include <queue>

std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    std::vector<std::vector<int>> res;
    if (root == nullptr) return res;

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int level_size = static_cast<int>(q.size());
        std::vector<int> current_level;
        current_level.reserve(level_size);

        for (int i = 0; i < level_size; ++i) {
            TreeNode* node = q.front();
            q.pop();
            current_level.push_back(node->val);

            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
        }
        res.push_back(std::move(current_level));
    }

    return res;
}
