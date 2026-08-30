#include <vector>

bool validTree(int n, const std::vector<std::vector<int>>& edges);

int main() {
    Tests.bool_check("Example 1", validTree(5, {{0, 1}, {0, 2}, {0, 3}, {1, 4}}) == true);
    Tests.bool_check("Example 2", validTree(5, {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}}) == false);
    return 0;
}
