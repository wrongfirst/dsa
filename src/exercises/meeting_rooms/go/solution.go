/**
 * Definition of Interval:
 * type Interval struct {
 *    Start int
 *    End   int
 * }
 */

func canAttendMeetings(intervals []Interval) bool {
    sort.Slice(intervals, func(i, j int) bool {
        return intervals[i].Start < intervals[j].Start
    })

    for i := 1; i < len(intervals); i++ {
        i1 := intervals[i-1]
        i2 := intervals[i]
        if i1.End > i2.Start {
            return false
        }
    }
    return true
}
