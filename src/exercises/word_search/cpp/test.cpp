#include <string>
#include <vector>

bool exist(std::vector<std::vector<char>>& board, const std::string& word);

int main() {
    std::vector<std::vector<char>> board1 = {
        {'A', 'B', 'C', 'D'},
        {'S', 'A', 'A', 'T'},
        {'A', 'C', 'A', 'E'}
    };
    Tests.bool_check("Example 1", exist(board1, "CAT") == true);

    std::vector<std::vector<char>> board2 = {
        {'A', 'B', 'C', 'D'},
        {'S', 'A', 'A', 'T'},
        {'A', 'C', 'A', 'E'}
    };
    Tests.bool_check("Example 2", exist(board2, "BAT") == false);

    return 0;
}
