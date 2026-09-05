type Codec struct {
    
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
