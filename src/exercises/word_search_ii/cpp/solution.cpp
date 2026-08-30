#include <string>
#include <vector>
#include <unordered_set>

namespace {
struct TrieNode {
    TrieNode* children[26];
    bool is_word;
    std::string word;
    TrieNode() : is_word(false), word("") {
        for (int i = 0; i < 26; ++i) children[i] = nullptr;
    }
};

void insert(TrieNode* root, const std::string& word) {
    TrieNode* curr = root;
    for (char c : word) {
        int idx = c - 'a';
        if (curr->children[idx] == nullptr) {
            curr->children[idx] = new TrieNode();
        }
        curr = curr->children[idx];
    }
    curr->is_word = true;
    curr->word = word;
}

void dfs(std::vector<std::vector<char>>& board, int r, int c, TrieNode* node, std::vector<std::string>& result) {
    if (r < 0 || r >= static_cast<int>(board.size()) ||
        c < 0 || c >= static_cast<int>(board[0].size()) ||
        board[r][c] == '#') {
        return;
    }

    char ch = board[r][c];
    int idx = ch - 'a';
    if (idx < 0 || idx >= 26 || node->children[idx] == nullptr) {
        return;
    }

    node = node->children[idx];
    if (node->is_word) {
        result.push_back(node->word);
        node->is_word = false; // Avoid duplicates
    }

    board[r][c] = '#';
    dfs(board, r + 1, c, node, result);
    dfs(board, r - 1, c, node, result);
    dfs(board, r, c + 1, node, result);
    dfs(board, r, c - 1, node, result);
    board[r][c] = ch;
}
} // namespace

std::vector<std::string> findWords(std::vector<std::vector<char>> board, const std::vector<std::string>& words) {
    TrieNode* root = new TrieNode();
    for (const auto& w : words) {
        insert(root, w);
    }

    std::vector<std::string> result;
    int rows = board.size();
    if (rows == 0) return result;
    int cols = board[0].size();

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            dfs(board, r, c, root, result);
        }
    }

    return result;
}
