func hammingWeight(n int) int {
	res := 0
	for n != 0 {
		n &= n - 1
		res++
	}
	return res
}
