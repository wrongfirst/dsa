#include <vector>
#include <unordered_set>
#include <functional>

bool validTree(int n, const std::vector<std::vector<int>>& edges) {
    if (n == 0) return true;
    if (static_cast<int>(edges.size()) != n - 1) return false;

    std::vector<std::vector<int>> adj(n);
    for (const auto& e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    std::unordered_set<int> visited;

    std::function<bool(int, int)> dfs = [&](int i, int prev) -> bool {
        if (visited.find(i) != visited.end()) {
            return false;
        }

        visited.insert(i);
        for (int j : adj[i]) {
            if (j == prev) continue;
            if (!dfs(j, i)) return false;
        }
        return true;
    };

    return dfs(0, -1) && static_cast<int>(visited.size()) == n;
}
