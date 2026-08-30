#include <vector>

int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals);

int main() {
    std::vector<std::vector<int>> i1 = {{1, 2}, {1, 4}, {2, 4}};
    Tests.equal_check("Example 1", 1, eraseOverlapIntervals(i1));

    std::vector<std::vector<int>> i2 = {{1, 2}, {2, 4}};
    Tests.equal_check("Example 2", 0, eraseOverlapIntervals(i2));

    return 0;
}
