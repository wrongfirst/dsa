#include <vector>
#include <functional>

bool canFinish(int numCourses, const std::vector<std::vector<int>>& prerequisites) {
    std::vector<std::vector<int>> pre_map(numCourses);
    for (const auto& p : prerequisites) {
        pre_map[p[0]].push_back(p[1]);
    }

    // 0 = unvisited, 1 = visiting, 2 = visited
    std::vector<int> state(numCourses, 0);

    std::function<bool(int)> dfs = [&](int crs) -> bool {
        if (state[crs] == 1) return false; // Cycle detected
        if (state[crs] == 2) return true;  // Already confirmed safe

        state[crs] = 1;
        for (int pre : pre_map[crs]) {
            if (!dfs(pre)) return false;
        }
        state[crs] = 2;
        return true;
    };

    for (int c = 0; c < numCourses; ++c) {
        if (!dfs(c)) return false;
    }
    return true;
}
