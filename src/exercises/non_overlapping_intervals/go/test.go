Tests.EqualCheck("Example 1", 1, eraseOverlapIntervals([][]int{{1, 2}, {1, 4}, {2, 4}}))
Tests.EqualCheck("Example 2", 0, eraseOverlapIntervals([][]int{{1, 2}, {2, 4}}))
