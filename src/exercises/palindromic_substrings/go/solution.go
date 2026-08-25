func countSubstrings(s string) int {
    res := 0
    for i := 0; i < len(s); i++ {
        res += countPali(s, i, i)
        res += countPali(s, i, i+1)
    }
    return res
}

func countPali(s string, l, r int) int {
    res := 0
    for l >= 0 && r < len(s) && s[l] == s[r] {
        res++
        l--
        r++
    }
    return res
}
