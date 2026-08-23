func minWindow(s string, t string) string {
    if t == "" {
        return ""
    }

    countT := make(map[rune]int)
    window := make(map[rune]int)

    for _, c := range t {
        countT[c]++
    }

    have, need := 0, len(countT)
    res := []int{-1, -1}
    resLen := math.Inf(1)
    l := 0

    for r, c := range s {
        window[c]++

        if val, ok := countT[c]; ok && window[c] == val {
            have++
        }

        for have == need {
            if float64(r-l+1) < resLen {
                res[0], res[1] = l, r
                resLen = float64(r - l + 1)
            }

            leftChar := rune(s[l])
            window[leftChar]--
            if val, ok := countT[leftChar]; ok && window[leftChar] < val {
                have--
            }
            l++
        }
    }

    if resLen == math.Inf(1) {
        return ""
    }
    return s[res[0] : res[1]+1]
}
