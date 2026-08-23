func longestConsecutive(nums []int) int {
	numSet := make(map[int]bool)
	for _, n := range nums {
		numSet[n] = true
	}
	longest := 0

	for n := range numSet {
		if !numSet[n-1] {
			length := 1
			for numSet[n+length] {
				length++
			}
			longest = max(length, longest)
		}
	}
	return longest
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
