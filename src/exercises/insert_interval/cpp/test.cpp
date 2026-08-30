#include <vector>

std::vector<std::vector<int>> insert(const std::vector<std::vector<int>>& intervals, const std::vector<int>& newInterval);

int main() {
    Tests.equal_check("Example 1",
        std::vector<std::vector<int>>{{1, 6}},
        insert({{1, 3}, {4, 6}}, {2, 5}));

    Tests.equal_check("Example 2",
        std::vector<std::vector<int>>{{1, 2}, {3, 5}, {6, 7}, {9, 10}},
        insert({{1, 2}, {3, 5}, {9, 10}}, {6, 7}));

    return 0;
}
