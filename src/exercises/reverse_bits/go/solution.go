func reverseBits(n int) int {
	res := 0
	for i := 0; i < 32; i++ {
		bit := (n >> i) & 1
		res += bit << (31 - i)
	}
	return res
}
