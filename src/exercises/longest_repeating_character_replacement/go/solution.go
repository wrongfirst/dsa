func characterReplacement(s string, k int) int {
	count := make(map[byte]int)

	l := 0
	maxf := 0
	r := 0
	for r = 0; r < len(s); r++ {
		count[s[r]] = 1 + count[s[r]]
		maxf = max(maxf, count[s[r]])
		if (r-l+1)-maxf > k {
			count[s[l]]--
			l++
		}
	}
	return r - l
}
