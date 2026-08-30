#include <string>

std::string minWindow(const std::string& s, const std::string& t);

int main() {
    Tests.equal_check("Example 1", std::string("YXAZ"), minWindow("OUZODYXAZV", "XYZ"));
    Tests.equal_check("Example 2", std::string("xyz"), minWindow("xyz", "xyz"));
    Tests.equal_check("Example 3", std::string(""), minWindow("x", "xy"));
    return 0;
}
