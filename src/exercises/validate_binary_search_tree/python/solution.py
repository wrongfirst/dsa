# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def isValidBST(root: TreeNode | None) -> bool:
    def valid(node: TreeNode | None, left: float, right: float) -> bool:
        if not node:
            return True
        if not (left < node.val < right):
            return False

        return valid(node.left, left, float(node.val)) and valid(
            node.right, float(node.val), right
        )

    return valid(root, float("-inf"), float("inf"))
