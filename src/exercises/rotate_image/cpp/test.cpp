#include <vector>

void rotate(std::vector<std::vector<int>>& matrix);

int main() {
    std::vector<std::vector<int>> m1 = {{3, 1}, {4, 2}};
    rotate(m1);
    Tests.equal_check("Example 1",
        std::vector<std::vector<int>>{{4, 3}, {2, 1}},
        m1);

    std::vector<std::vector<int>> m2 = {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};
    rotate(m2);
    Tests.equal_check("Example 2",
        std::vector<std::vector<int>>{{9, 8, 7}, {6, 5, 4}, {3, 2, 1}},
        m2);

    return 0;
}
