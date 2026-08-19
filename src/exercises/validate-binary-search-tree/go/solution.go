/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func isValidBST(root *TreeNode) bool {
    var valid func(node *TreeNode, left int, right int) bool
    valid = func(node *TreeNode, left int, right int) bool {
        if node == nil {
            return true
        }
        
        if !(left < node.Val && node.Val < right) {
            return false
        }
        
        return valid(node.Left, left, node.Val) && valid(node.Right, node.Val, right)
    }
    
    return valid(root, math.MinInt, math.MaxInt)
}
