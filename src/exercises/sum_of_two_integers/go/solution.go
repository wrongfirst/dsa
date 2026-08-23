func getSum(a int, b int) int {
	var add func(x, y int) int
	add = func(x, y int) int {
		if x == 0 || y == 0 {
			if x != 0 {
				return x
			}
			return y
		}
		return add(x^y, (x&y)<<1)
	}

	if a*b < 0 {
		if a > 0 {
			return getSum(b, a)
		}
		if add(^a, 1) == b {
			return 0
		}
		if add(^a, 1) < b {
			return add(^(add(add(^a, 1), add(^b, 1))), 1)
		}
	}

	return add(a, b)
}
