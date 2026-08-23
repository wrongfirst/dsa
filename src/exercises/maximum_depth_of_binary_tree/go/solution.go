/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

// RECURSIVE DFS
func maxDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    
    return 1 + max(maxDepth(root.Left), maxDepth(root.Right))
}

// ITERATIVE DFS
// func maxDepth(root *TreeNode) int {
//     type NodeDepth struct {
//         node  *TreeNode
//         depth int
//     }
//     
//     stack := []NodeDepth{{root, 1}}
//     res := 0
//     
//     for len(stack) > 0 {
//         nd := stack[len(stack)-1]
//         stack = stack[:len(stack)-1]
//         
//         if nd.node != nil {
//             res = max(res, nd.depth)
//             stack = append(stack, NodeDepth{nd.node.Left, nd.depth + 1})
//             stack = append(stack, NodeDepth{nd.node.Right, nd.depth + 1})
//         }
//     }
//     
//     return res
// }

// BFS
// func maxDepth(root *TreeNode) int {
//     if root == nil {
//         return 0
//     }
//     
//     queue := []*TreeNode{root}
//     level := 0
//     
//     for len(queue) > 0 {
//         qLen := len(queue)
//         for i := 0; i < qLen; i++ {
//             node := queue[0]
//             queue = queue[1:]
//             
//             if node.Left != nil {
//                 queue = append(queue, node.Left)
//             }
//             if node.Right != nil {
//                 queue = append(queue, node.Right)
//             }
//         }
//         level++
//     }
//     
//     return level
// }
