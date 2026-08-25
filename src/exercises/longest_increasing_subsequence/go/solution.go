func lengthOfLIS(nums []int) int {
    lis := make([]int, len(nums))
    for i := 0; i < len(nums); i++ {
        lis[i] = 1
    }

    for i := len(nums) - 1; i >= 0; i-- {
        for j := i + 1; j < len(nums); j++ {
            if nums[i] < nums[j] {
                lis[i] = max(lis[i], 1+lis[j])
            }
        }
    }

    result := lis[0]
    for i := 1; i < len(lis); i++ {
        result = max(result, lis[i])
    }
    return result
}
