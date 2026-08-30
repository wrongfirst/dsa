#include <vector>
#include <algorithm>

std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
    if (intervals.empty()) return {};

    std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[0] < b[0];
    });

    std::vector<std::vector<int>> output;
    output.push_back(intervals[0]);

    for (size_t i = 1; i < intervals.size(); ++i) {
        int last_end = output.back()[1];
        int start = intervals[i][0];
        int end = intervals[i][1];

        if (start <= last_end) {
            output.back()[1] = std::max(last_end, end);
        } else {
            output.push_back(intervals[i]);
        }
    }

    return output;
}
