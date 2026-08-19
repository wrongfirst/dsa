type PrefixTreeNode struct {
    children [26]*PrefixTreeNode
    end      bool
}

type PrefixTree struct {
    root *PrefixTreeNode
}

func Constructor() PrefixTree {
    return PrefixTree{root: &PrefixTreeNode{}}
}

func (this *PrefixTree) Insert(word string) {
    curr := this.root
    for _, c := range word {
        i := int(c - 'a')
        if curr.children[i] == nil {
            curr.children[i] = &PrefixTreeNode{}
        }
        curr = curr.children[i]
    }
    curr.end = true
}

func (this *PrefixTree) Search(word string) bool {
    curr := this.root
    for _, c := range word {
        i := int(c - 'a')
        if curr.children[i] == nil {
            return false
        }
        curr = curr.children[i]
    }
    return curr.end
}

func (this *PrefixTree) StartsWith(prefix string) bool {
    curr := this.root
    for _, c := range prefix {
        i := int(c - 'a')
        if curr.children[i] == nil {
            return false
        }
        curr = curr.children[i]
    }
    return true
}
