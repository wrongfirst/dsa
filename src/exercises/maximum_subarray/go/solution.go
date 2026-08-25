func maxSubArray(nums []int) int {
    res := nums[0]
    total := 0

    for _, n := range nums {
        total += n
        res = max(res, total)
        if total < 0 {
            total = 0
        }
    }
    return res
}
