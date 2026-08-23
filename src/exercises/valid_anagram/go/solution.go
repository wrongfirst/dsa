func isAnagram(s string, t string) bool {
    if len(s) != len(t) {
        return false
    }
    
    countS, countT := make(map[rune]int), make(map[rune]int)
    
    for i := range s {
        countS[rune(s[i])] = 1 + countS[rune(s[i])]
        countT[rune(t[i])] = 1 + countT[rune(t[i])]
    }
    
    if len(countS) != len(countT) {
        return false
    }
    for k, v := range countS {
        if countT[k] != v {
            return false
        }
    }
    return true
}
