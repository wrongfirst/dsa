#include <vector>

std::vector<std::vector<int>> pacificAtlantic(const std::vector<std::vector<int>>& heights);

int main() {
    std::vector<std::vector<int>> h1 = {
        {4, 2, 7, 3, 4},
        {7, 4, 6, 4, 7},
        {6, 3, 5, 3, 6}
    };
    Tests.unordered_equal_check("Example 1",
        std::vector<std::vector<int>>{{0, 2}, {0, 4}, {1, 0}, {1, 1}, {1, 2}, {1, 3}, {1, 4}, {2, 0}},
        pacificAtlantic(h1));

    std::vector<std::vector<int>> h2 = {
        {1},
        {1}
    };
    Tests.unordered_equal_check("Example 2",
        std::vector<std::vector<int>>{{0, 0}, {1, 0}},
        pacificAtlantic(h2));

    return 0;
}
