#include <vector>
#include <algorithm>

bool canAttendMeetings(std::vector<Interval>& intervals) {
    std::sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
        return a.start < b.start;
    });

    for (size_t i = 1; i < intervals.size(); ++i) {
        if (intervals[i - 1].end > intervals[i].start) {
            return false;
        }
    }
    return true;
}
