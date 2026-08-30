#include <vector>

int numIslands(std::vector<std::vector<char>>& grid);

int main() {
    std::vector<std::vector<char>> g1 = {
        {'0', '1', '1', '1', '0'},
        {'0', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    Tests.equal_check("Example 1", 1, numIslands(g1));

    std::vector<std::vector<char>> g2 = {
        {'1', '1', '0', '0', '1'},
        {'1', '1', '0', '0', '1'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    Tests.equal_check("Example 2", 4, numIslands(g2));

    return 0;
}
