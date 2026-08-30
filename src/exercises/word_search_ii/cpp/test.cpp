#include <string>
#include <vector>

std::vector<std::string> findWords(std::vector<std::vector<char>> board, const std::vector<std::string>& words);

int main() {
    std::vector<std::vector<char>> board1 = {
        {'a', 'b', 'c', 'd'},
        {'s', 'a', 'a', 't'},
        {'a', 'c', 'k', 'e'},
        {'a', 'c', 'd', 'n'}
    };
    std::vector<std::string> words1 = {"bat", "cat", "back", "backend", "stack"};
    Tests.unordered_equal_check("Example 1",
        std::vector<std::string>{"back", "backend", "cat"},
        findWords(board1, words1));

    std::vector<std::vector<char>> board2 = {
        {'x', 'o'},
        {'x', 'o'}
    };
    std::vector<std::string> words2 = {"xoxo"};
    Tests.unordered_equal_check("Example 2",
        std::vector<std::string>{},
        findWords(board2, words2));

    return 0;
}
