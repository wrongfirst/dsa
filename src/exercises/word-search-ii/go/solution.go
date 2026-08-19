type TrieNode struct {
    children map[byte]*TrieNode
    isWord   bool
    refs     int
}

func (this *TrieNode) addWord(word string) {
    cur := this
    cur.refs++
    for i := 0; i < len(word); i++ {
        c := word[i]
        if cur.children[c] == nil {
            cur.children[c] = &TrieNode{children: make(map[byte]*TrieNode)}
        }
        cur = cur.children[c]
        cur.refs++
    }
    cur.isWord = true
}

func (this *TrieNode) removeWord(word string) {
    cur := this
    cur.refs--
    for i := 0; i < len(word); i++ {
        c := word[i]
        if cur.children[c] != nil {
            cur = cur.children[c]
            cur.refs--
        }
    }
}

func findWords(board [][]byte, words []string) []string {
    root := &TrieNode{children: make(map[byte]*TrieNode)}
    for _, w := range words {
        root.addWord(w)
    }

    ROWS, COLS := len(board), len(board[0])
    res := make(map[string]bool)
    visit := make(map[[2]int]bool)

    var dfs func(r, c int, node *TrieNode, word string)
    dfs = func(r, c int, node *TrieNode, word string) {
        if r < 0 || r >= ROWS || c < 0 || c >= COLS ||
           node.children[board[r][c]] == nil ||
           node.children[board[r][c]].refs < 1 ||
           visit[[2]int{r, c}] {
            return
        }

        visit[[2]int{r, c}] = true
        node = node.children[board[r][c]]
        word += string(board[r][c])

        if node.isWord {
            node.isWord = false
            res[word] = true
            root.removeWord(word)
        }

        dfs(r+1, c, node, word)
        dfs(r-1, c, node, word)
        dfs(r, c+1, node, word)
        dfs(r, c-1, node, word)

        delete(visit, [2]int{r, c})
    }

    for r := 0; r < ROWS; r++ {
        for c := 0; c < COLS; c++ {
            dfs(r, c, root, "")
        }
    }

    result := make([]string, 0, len(res))
    for word := range res {
        result = append(result, word)
    }
    return result
}
