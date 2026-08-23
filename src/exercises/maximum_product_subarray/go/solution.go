func maxProduct(nums []int) int {
    res := nums[0]
    curMin, curMax := 1, 1

    for _, n := range nums {
        tmp := curMax * n
        curMax = max(n*curMax, n*curMin, n)
        curMin = min(tmp, n*curMin, n)
        res = max(res, curMax)
    }
    return res
}
