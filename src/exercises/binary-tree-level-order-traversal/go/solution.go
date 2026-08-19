/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func levelOrder(root *TreeNode) [][]int {
    var res [][]int
    if root == nil {
        return res
    }

    queue := []*TreeNode{root}

    for len(queue) > 0 {
        levelSize := len(queue)
        var levelVals []int

        for i := 0; i < levelSize; i++ {
            node := queue[0]
            queue = queue[1:]
            levelVals = append(levelVals, node.Val)

            if node.Left != nil {
                queue = append(queue, node.Left)
            }
            if node.Right != nil {
                queue = append(queue, node.Right)
            }
        }

        res = append(res, levelVals)
    }

    return res
}
