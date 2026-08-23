/**
 * Definition of Interval:
 * type Interval struct {
 *    start int
 *    end   int
 * }
 */

func minMeetingRooms(intervals []Interval) int {
    time := [][]int{}
    for _, i := range intervals {
        start, end := i.start, i.end
        time = append(time, []int{start, 1})
        time = append(time, []int{end, -1})
    }

    sort.Slice(time, func(i, j int) bool {
        if time[i][0] == time[j][0] {
            return time[i][1] < time[j][1]
        }
        return time[i][0] < time[j][0]
    })

    count := 0
    maxCount := 0
    for _, t := range time {
        count += t[1]
        if count > maxCount {
            maxCount = count
        }
    }

    return maxCount
}
