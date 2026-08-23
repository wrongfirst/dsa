s = Solution()
Tests.equal_check("Example 1", 2, s.minMeetingRooms([Interval(0, 40), Interval(5, 10), Interval(15, 20)]))
Tests.equal_check("Example 2", 1, s.minMeetingRooms([Interval(4, 9)]))
