Tests.BoolCheck("Example 1", canAttendMeetings([]Interval{{0, 30}, {5, 10}, {15, 20}}) == false)
Tests.BoolCheck("Example 2", canAttendMeetings([]Interval{{5, 8}, {9, 15}}) == true)
