type Codec struct {
    i int
}

func Constructor() Codec {
    return Codec{}
}

// Serializes a tree to a single string.
func (this *Codec) Serialize(root *TreeNode) string {
    var res []string
    
    var dfs func(node *TreeNode)
    dfs = func(node *TreeNode) {
        if node == nil {
            res = append(res, "N")
            return
        }
        res = append(res, strconv.Itoa(node.Val))
        dfs(node.Left)
        dfs(node.Right)
    }
    
    dfs(root)
    return strings.Join(res, ",")
}

// Deserializes your encoded data to tree.
func (this *Codec) Deserialize(data string) *TreeNode {
    vals := strings.Split(data, ",")
    this.i = 0
    
    var dfs func() *TreeNode
    dfs = func() *TreeNode {
        if vals[this.i] == "N" {
            this.i++
            return nil
        }
        val, _ := strconv.Atoi(vals[this.i])
        node := &TreeNode{Val: val}
        this.i++
        node.Left = dfs()
        node.Right = dfs()
        return node
    }
    
    return dfs()
}

func (this *Codec) serialize(root *TreeNode) string {
    return this.Serialize(root)
}

func (this *Codec) deserialize(data string) *TreeNode {
    return this.Deserialize(data)
}
