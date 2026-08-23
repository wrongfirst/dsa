func isValid(str string) bool {
	Map := map[rune]rune{')': '(', ']': '[', '}': '{'}
	stack := []rune{}

	for _, c := range str {
		if _, ok := Map[c]; !ok {
			stack = append(stack, c)
			continue
		}
		if len(stack) == 0 || stack[len(stack)-1] != Map[c] {
			return false
		}
		stack = stack[:len(stack)-1]
	}

	return len(stack) == 0
}
