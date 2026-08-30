# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


def isSubtree(root: TreeNode | None, subRoot: TreeNode | None) -> bool:
    if not subRoot:
        return True
    if not root:
        return False

    if sameTree(root, subRoot):
        return True
    return isSubtree(root.left, subRoot) or isSubtree(root.right, subRoot)

def sameTree(root: TreeNode | None, subRoot: TreeNode | None) -> bool:
    if not root and not subRoot:
        return True
    if root and subRoot and root.val == subRoot.val:
        return sameTree(root.left, subRoot.left) and sameTree(root.right, subRoot.right)
    return False
