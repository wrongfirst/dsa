#include <vector>

int countComponents(int n, const std::vector<std::vector<int>>& edges);

int main() {
    Tests.equal_check("Example 1", 2, countComponents(5, {{0, 1}, {1, 2}, {3, 4}}));
    Tests.equal_check("Example 2", 1, countComponents(5, {{0, 1}, {1, 2}, {2, 3}, {3, 4}}));
    Tests.equal_check("No edges", 3, countComponents(3, {}));
    return 0;
}
