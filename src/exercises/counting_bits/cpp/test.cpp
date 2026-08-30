#include <vector>

std::vector<int> countBits(int n);

int main() {
    Tests.equal_check("Example 1", std::vector<int>{0, 1, 1, 2, 1}, countBits(4));
    Tests.equal_check("n = 0", std::vector<int>{0}, countBits(0));
    return 0;
}
