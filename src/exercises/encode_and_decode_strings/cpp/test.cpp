#include <string>
#include <vector>

std::string encode(const std::vector<std::string>& strs);
std::vector<std::string> decode(const std::string& s);

int main() {
    Tests.equal_check("Example 1", std::vector<std::string>{"Hello", "World"}, decode(encode({"Hello", "World"})));
    Tests.equal_check("Example 2", std::vector<std::string>{""}, decode(encode({""})));
    Tests.equal_check("Empty vector", std::vector<std::string>{}, decode(encode({})));
    Tests.equal_check("Delimiter in content", std::vector<std::string>{"#", "##", "4#test", "10#hello#world"}, decode(encode({"#", "##", "4#test", "10#hello#world"})));
    Tests.equal_check("Max length strings", std::vector<std::string>{std::string(199, 'a'), std::string(199, 'b')}, decode(encode({std::string(199, 'a'), std::string(199, 'b')})));
    return 0;
}
