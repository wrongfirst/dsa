Tests.bool_check("Example 1", canAttendMeetings([Interval(0, 30), Interval(5, 10), Interval(15, 20)]) == False)
Tests.bool_check("Example 2", canAttendMeetings([Interval(5, 8), Interval(9, 15)]) == True)
