#include <vector>

void setZeroes(std::vector<std::vector<int>>& matrix);

int main() {
    std::vector<std::vector<int>> m1 = {{0, 0}, {0, 0}};
    setZeroes(m1);
    Tests.equal_check("Example 1",
        std::vector<std::vector<int>>{{0, 0}, {0, 0}},
        m1);

    std::vector<std::vector<int>> m2 = {{1, 0, 3}, {0, 0, 0}, {6, 0, 8}};
    setZeroes(m2);
    Tests.equal_check("Example 2",
        std::vector<std::vector<int>>{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
        m2);

    return 0;
}
