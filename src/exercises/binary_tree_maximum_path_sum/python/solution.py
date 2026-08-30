# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def maxPathSum(root: TreeNode | None) -> int:
    if not root:
        return 0

    res = [root.val]

    def dfs(node: TreeNode | None) -> int:
        if not node:
            return 0

        leftMax = max(dfs(node.left), 0)
        rightMax = max(dfs(node.right), 0)

        res[0] = max(res[0], node.val + leftMax + rightMax)
        return node.val + max(leftMax, rightMax)

    dfs(root)
    return res[0]
