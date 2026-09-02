type Codec struct {
    i int
}

func Constructor() Codec {
    return Codec{}
}

// Serializes a tree to a single string.
func (this *Codec) Serialize(root *TreeNode) string {
    return ""
}

// Deserializes your encoded data to tree.
func (this *Codec) Deserialize(data string) *TreeNode {
    return nil
}

func (this *Codec) serialize(root *TreeNode) string {
    return this.Serialize(root)
}

func (this *Codec) deserialize(data string) *TreeNode {
    return this.Deserialize(data)
}
