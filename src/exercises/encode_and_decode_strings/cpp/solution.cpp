#include <string>
#include <vector>

std::string encode(const std::vector<std::string>& strs) {
    std::string res = "";
    for (const auto& s : strs) {
        res += std::to_string(s.length()) + "#" + s;
    }
    return res;
}

std::vector<std::string> decode(const std::string& s) {
    std::vector<std::string> res;
    size_t i = 0;
    while (i < s.length()) {
        size_t j = i;
        while (j < s.length() && s[j] != '#') {
            j++;
        }
        int len = std::stoi(s.substr(i, j - i));
        i = j + 1;
        res.push_back(s.substr(i, len));
        i += len;
    }
    return res;
}
