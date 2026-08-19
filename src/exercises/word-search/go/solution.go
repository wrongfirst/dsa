func exist(board [][]byte, word string) bool {
    m := len(board)
    n := len(board[0])

    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if board[i][j] == word[0] {
                if dfs(board, word, 0, i, j, m, n) {
                    return true
                }
            }
        }
    }

    return false
}

func dfs(board [][]byte, word string, index, i, j, m, n int) bool {
    if i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[index] {
        return false
    }
    if index == len(word)-1 {
        return true
    }

    temp := board[i][j]
    board[i][j] = '#'

    if dfs(board, word, index+1, i-1, j, m, n) ||
        dfs(board, word, index+1, i+1, j, m, n) ||
        dfs(board, word, index+1, i, j-1, m, n) ||
        dfs(board, word, index+1, i, j+1, m, n) {
        return true
    }

    board[i][j] = temp
    return false
}
