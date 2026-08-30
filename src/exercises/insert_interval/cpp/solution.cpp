#include <vector>
#include <algorithm>

std::vector<std::vector<int>> insert(const std::vector<std::vector<int>>& intervals, const std::vector<int>& newInterval) {
    std::vector<std::vector<int>> res;
    std::vector<int> new_int = newInterval;
    size_t i = 0;
    size_t n = intervals.size();

    while (i < n) {
        if (new_int[1] < intervals[i][0]) {
            res.push_back(new_int);
            while (i < n) {
                res.push_back(intervals[i]);
                i++;
            }
            return res;
        } else if (new_int[0] > intervals[i][1]) {
            res.push_back(intervals[i]);
        } else {
            new_int[0] = std::min(new_int[0], intervals[i][0]);
            new_int[1] = std::max(new_int[1], intervals[i][1]);
        }
        i++;
    }

    res.push_back(new_int);
    return res;
}
