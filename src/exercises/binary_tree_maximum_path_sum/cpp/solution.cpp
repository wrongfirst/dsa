#include <algorithm>
#include <climits>
#include <functional>

int maxPathSum(TreeNode* root) {
    if (root == nullptr) return 0;
    int max_sum = INT_MIN;

    std::function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
        if (node == nullptr) return 0;

        int left_gain = std::max(dfs(node->left), 0);
        int right_gain = std::max(dfs(node->right), 0);

        int current_path = node->val + left_gain + right_gain;
        max_sum = std::max(max_sum, current_path);

        return node->val + std::max(left_gain, right_gain);
    };

    dfs(root);
    return max_sum;
}
