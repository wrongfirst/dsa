func eraseOverlapIntervals(intervals [][]int) int {
    sort.Slice(intervals, func(i, j int) bool {
        if intervals[i][0] == intervals[j][0] {
            return intervals[i][1] < intervals[j][1]
        }
        return intervals[i][0] < intervals[j][0]
    })

    res := 0
    prevEnd := intervals[0][1]

    for i := 1; i < len(intervals); i++ {
        start, end := intervals[i][0], intervals[i][1]
        if start >= prevEnd {
            prevEnd = end
        } else {
            res++
            if end < prevEnd {
                prevEnd = end
            }
        }
    }

    return res
}
