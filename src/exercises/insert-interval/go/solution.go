func insert(intervals [][]int, newInterval []int) [][]int {
    res := [][]int{}

    for i := 0; i < len(intervals); i++ {
        if newInterval[1] < intervals[i][0] {
            res = append(res, newInterval)
            res = append(res, intervals[i:]...)
            return res
        } else if newInterval[0] > intervals[i][1] {
            res = append(res, intervals[i])
        } else {
            newInterval = []int{
                min(newInterval[0], intervals[i][0]),
                max(newInterval[1], intervals[i][1]),
            }
        }
    }
    res = append(res, newInterval)
    return res
}
