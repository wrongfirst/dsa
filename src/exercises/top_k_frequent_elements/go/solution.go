func topKFrequent(nums []int, k int) []int {
	count := make(map[int]int)
	freq := make([][]int, len(nums)+1)
	
	for _, n := range nums {
		count[n] = 1 + count[n]
	}
	
	for n, c := range count {
		freq[c] = append(freq[c], n)
	}
	
	res := []int{}
	for i := len(freq) - 1; i > 0; i-- {
		for _, n := range freq[i] {
			res = append(res, n)
			if len(res) == k {
				return res
			}
		}
	}
	return res
}
