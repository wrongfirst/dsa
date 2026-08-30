#include <vector>
#include <functional>

std::vector<std::vector<int>> pacificAtlantic(const std::vector<std::vector<int>>& heights) {
    int rows = heights.size();
    if (rows == 0) return {};
    int cols = heights[0].size();

    std::vector<std::vector<bool>> pac(rows, std::vector<bool>(cols, false));
    std::vector<std::vector<bool>> atl(rows, std::vector<bool>(cols, false));

    std::function<void(int, int, std::vector<std::vector<bool>>&, int)> dfs =
        [&](int r, int c, std::vector<std::vector<bool>>& visit, int prev_height) {
            if (r < 0 || r >= rows || c < 0 || c >= cols || visit[r][c] || heights[r][c] < prev_height) {
                return;
            }
            visit[r][c] = true;
            dfs(r + 1, c, visit, heights[r][c]);
            dfs(r - 1, c, visit, heights[r][c]);
            dfs(r, c + 1, visit, heights[r][c]);
            dfs(r, c - 1, visit, heights[r][c]);
        };

    for (int c = 0; c < cols; ++c) {
        dfs(0, c, pac, heights[0][c]);
        dfs(rows - 1, c, atl, heights[rows - 1][c]);
    }

    for (int r = 0; r < rows; ++r) {
        dfs(r, 0, pac, heights[r][0]);
        dfs(r, cols - 1, atl, heights[r][cols - 1]);
    }

    std::vector<std::vector<int>> res;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (pac[r][c] && atl[r][c]) {
                res.push_back({r, c});
            }
        }
    }

    return res;
}
