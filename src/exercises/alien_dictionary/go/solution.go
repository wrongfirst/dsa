func foreignDictionary(words []string) string {
    adj := make(map[rune]map[rune]bool)
    for _, word := range words {
        for _, char := range word {
            if _, exists := adj[char]; !exists {
                adj[char] = make(map[rune]bool)
            }
        }
    }

    for i := 0; i < len(words)-1; i++ {
        w1, w2 := words[i], words[i+1]
        minLen := len(w1)
        if len(w2) < minLen {
            minLen = len(w2)
        }
        if len(w1) > len(w2) && w1[:minLen] == w2[:minLen] {
            return ""
        }
        for j := 0; j < minLen; j++ {
            if w1[j] != w2[j] {
                adj[rune(w1[j])][rune(w2[j])] = true
                break
            }
        }
    }

    visited := make(map[rune]bool)
    res := []rune{}

    var dfs func(char rune) bool
    dfs = func(char rune) bool {
        if val, exists := visited[char]; exists {
            return val
        }

        visited[char] = true

        for neighChar := range adj[char] {
            if dfs(neighChar) {
                return true
            }
        }

        visited[char] = false
        res = append(res, char)
        return false
    }

    for char := range adj {
        if dfs(char) {
            return ""
        }
    }

    for i, j := 0, len(res)-1; i < j; i, j = i+1, j-1 {
        res[i], res[j] = res[j], res[i]
    }
    return string(res)
}
