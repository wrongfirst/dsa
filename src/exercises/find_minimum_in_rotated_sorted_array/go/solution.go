func findMin(nums []int) int {
	start, end := 0, len(nums)-1
	currMin := math.MaxInt32

	for start < end {
		mid := start + (end-start)/2
		currMin = min(currMin, nums[mid])

		// right has the min
		if nums[mid] > nums[end] {
			start = mid + 1

			// left has the min
		} else {
			end = mid - 1

		}
	}

	return min(currMin, nums[start])
}
