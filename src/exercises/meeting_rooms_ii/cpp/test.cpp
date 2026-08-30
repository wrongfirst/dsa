#include <vector>

int minMeetingRooms(const std::vector<Interval>& intervals);

int main() {
    std::vector<Interval> i1 = {Interval(0, 40), Interval(5, 10), Interval(15, 20)};
    Tests.equal_check("Example 1", 2, minMeetingRooms(i1));

    std::vector<Interval> i2 = {Interval(4, 9)};
    Tests.equal_check("Example 2", 1, minMeetingRooms(i2));

    std::vector<Interval> i3 = {};
    Tests.equal_check("Empty", 0, minMeetingRooms(i3));
    return 0;
}
