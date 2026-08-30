#include <vector>

std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals);

int main() {
    std::vector<std::vector<int>> i1 = {{1, 5}, {1, 5}, {6, 7}};
    Tests.equal_check("Example 1",
        std::vector<std::vector<int>>{{1, 5}, {6, 7}},
        merge(i1));

    std::vector<std::vector<int>> i2 = {{1, 3}, {2, 3}};
    Tests.equal_check("Example 2",
        std::vector<std::vector<int>>{{1, 3}},
        merge(i2));

    return 0;
}
