#include <vector>
#include <algorithm>

int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
    if (intervals.empty()) return 0;

    std::sort(intervals.begin(), intervals.end());

    int res = 0;
    int prev_end = intervals[0][1];

    for (size_t i = 1; i < intervals.size(); ++i) {
        int start = intervals[i][0];
        int end = intervals[i][1];

        if (start >= prev_end) {
            prev_end = end;
        } else {
            res++;
            prev_end = std::min(end, prev_end);
        }
    }

    return res;
}
