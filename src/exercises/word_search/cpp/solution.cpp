#include <string>
#include <vector>

static bool dfs(std::vector<std::vector<char>>& board, const std::string& word, size_t index, int i, int j, int m, int n) {
    if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[index]) {
        return false;
    }
    if (index == word.length() - 1) {
        return true;
    }

    char original = board[i][j];
    board[i][j] = '#';

    bool res = dfs(board, word, index + 1, i - 1, j, m, n) ||
               dfs(board, word, index + 1, i + 1, j, m, n) ||
               dfs(board, word, index + 1, i, j - 1, m, n) ||
               dfs(board, word, index + 1, i, j + 1, m, n);

    board[i][j] = original;
    return res;
}

bool exist(std::vector<std::vector<char>>& board, const std::string& word) {
    int m = board.size();
    if (m == 0) return false;
    int n = board[0].size();

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == word[0]) {
                if (dfs(board, word, 0, i, j, m, n)) {
                    return true;
                }
            }
        }
    }
    return false;
}
