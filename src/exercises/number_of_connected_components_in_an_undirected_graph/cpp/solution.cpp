#include <vector>
#include <numeric>

namespace {
struct DSU {
    std::vector<int> parent;
    int count;

    DSU(int n) : parent(n), count(n) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            count--;
        }
    }
};
} // namespace

int countComponents(int n, const std::vector<std::vector<int>>& edges) {
    DSU dsu(n);
    for (const auto& e : edges) {
        dsu.unite(e[0], e[1]);
    }
    return dsu.count;
}
