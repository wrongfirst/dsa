func isPalindrome(s string) bool {
	l, r := 0, len(s)-1
	for l < r {
		for l < r && !alphaNum(s[l]) {
			l++
		}
		for r > l && !alphaNum(s[r]) {
			r--
		}
		if strings.ToLower(string(s[l])) != strings.ToLower(string(s[r])) {
			return false
		}
		l, r = l+1, r-1
	}
	return true
}

func alphaNum(c byte) bool {
	return ('A' <= c && c <= 'Z') ||
		('a' <= c && c <= 'z') ||
		('0' <= c && c <= '9')
}
