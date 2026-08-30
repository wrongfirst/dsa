#include <vector>

bool canFinish(int numCourses, const std::vector<std::vector<int>>& prerequisites);

int main() {
    Tests.bool_check("Example 1", canFinish(2, {{0, 1}}) == true);
    Tests.bool_check("Example 2", canFinish(2, {{0, 1}, {1, 0}}) == false);
    return 0;
}
