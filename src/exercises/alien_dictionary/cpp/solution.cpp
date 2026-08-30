#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <functional>

std::string foreignDictionary(const std::vector<std::string>& words) {
    std::map<char, std::set<char>> adj;
    for (const auto& w : words) {
        for (char c : w) {
            adj[c]; // Ensure key exists
        }
    }

    for (size_t i = 0; i + 1 < words.size(); ++i) {
        const std::string& w1 = words[i];
        const std::string& w2 = words[i + 1];
        size_t min_len = std::min(w1.length(), w2.length());

        if (w1.length() > w2.length() && w1.substr(0, min_len) == w2.substr(0, min_len)) {
            return "";
        }

        for (size_t j = 0; j < min_len; ++j) {
            if (w1[j] != w2[j]) {
                adj[w1[j]].insert(w2[j]);
                break;
            }
        }
    }

    // 0 = unvisited, 1 = visiting (in path), 2 = visited
    std::map<char, int> state;
    std::string res;

    std::function<bool(char)> dfs = [&](char c) -> bool {
        if (state[c] == 1) return true;  // Cycle detected
        if (state[c] == 2) return false; // Already visited

        state[c] = 1;
        for (char nei : adj[c]) {
            if (dfs(nei)) return true;
        }
        state[c] = 2;
        res += c;
        return false;
    };

    for (const auto& pair : adj) {
        if (state[pair.first] == 0) {
            if (dfs(pair.first)) {
                return "";
            }
        }
    }

    std::reverse(res.begin(), res.end());
    return res;
}
