#include <string>

int numDecodings(const std::string& s);

int main() {
    Tests.equal_check("Example 1", 2, numDecodings("12"));
    Tests.equal_check("Example 2", 3, numDecodings("226"));
    Tests.equal_check("Example 3", 0, numDecodings("06"));
    return 0;
}
