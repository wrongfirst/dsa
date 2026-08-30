#include <vector>
#include <algorithm>
#include <utility>

int minMeetingRooms(const std::vector<Interval>& intervals) {
    std::vector<std::pair<int, int>> time_events;
    for (const auto& i : intervals) {
        time_events.push_back({i.start, 1});
        time_events.push_back({i.end, -1});
    }

    std::sort(time_events.begin(), time_events.end());

    int count = 0;
    int max_count = 0;
    for (const auto& t : time_events) {
        count += t.second;
        max_count = std::max(max_count, count);
    }
    return max_count;
}
