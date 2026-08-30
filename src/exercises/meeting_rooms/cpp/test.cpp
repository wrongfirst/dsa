#include <vector>

bool canAttendMeetings(std::vector<Interval>& intervals);

int main() {
    std::vector<Interval> i1 = {Interval(0, 30), Interval(5, 10), Interval(15, 20)};
    Tests.bool_check("Example 1", canAttendMeetings(i1) == false);

    std::vector<Interval> i2 = {Interval(5, 8), Interval(9, 15)};
    Tests.bool_check("Example 2", canAttendMeetings(i2) == true);

    std::vector<Interval> i3 = {};
    Tests.bool_check("Empty intervals", canAttendMeetings(i3) == true);
    return 0;
}
