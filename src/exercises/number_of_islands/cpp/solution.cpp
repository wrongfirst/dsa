#include <vector>

static void dfs(std::vector<std::vector<char>>& grid, int r, int c, int rows, int cols) {
    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != '1') {
        return;
    }

    grid[r][c] = '0';
    dfs(grid, r + 1, c, rows, cols);
    dfs(grid, r - 1, c, rows, cols);
    dfs(grid, r, c + 1, rows, cols);
    dfs(grid, r, c - 1, rows, cols);
}

int numIslands(std::vector<std::vector<char>>& grid) {
    int rows = grid.size();
    if (rows == 0) return 0;
    int cols = grid[0].size();
    int count = 0;

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (grid[r][c] == '1') {
                count++;
                dfs(grid, r, c, rows, cols);
            }
        }
    }

    return count;
}
