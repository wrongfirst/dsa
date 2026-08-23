type TrieNode struct {
    children map[string]*TrieNode
    word     bool
}

type WordDictionary struct {
    root *TrieNode
}

func Constructor() WordDictionary {
    return WordDictionary{root: &TrieNode{children: make(map[string]*TrieNode)}}
}

func (this *WordDictionary) AddWord(word string) {
    cur := this.root
    for _, c := range word {
        char := string(c)
        if cur.children[char] == nil {
            cur.children[char] = &TrieNode{children: make(map[string]*TrieNode)}
        }
        cur = cur.children[char]
    }
    cur.word = true
}

func (this *WordDictionary) Search(word string) bool {
    var dfs func(j int, root *TrieNode) bool
    dfs = func(j int, root *TrieNode) bool {
        cur := root
        for i := j; i < len(word); i++ {
            c := string(word[i])
            if c == "." {
                for _, child := range cur.children {
                    if dfs(i+1, child) {
                        return true
                    }
                }
                return false
            } else {
                if cur.children[c] == nil {
                    return false
                }
                cur = cur.children[c]
            }
        }
        return cur.word
    }
    return dfs(0, this.root)
}
