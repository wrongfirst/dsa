#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> map;
    for (const auto& s : strs) {
        std::string key = s;
        std::sort(key.begin(), key.end());
        map[key].push_back(s);
    }
    std::vector<std::vector<std::string>> result;
    result.reserve(map.size());
    for (auto& pair : map) {
        result.push_back(std::move(pair.second));
    }
    return result;
}
