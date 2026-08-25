def foreignDictionary(words: list[str]) -> str:
    adj: dict[str, set[str]] = {char: set() for word in words for char in word}

    for i in range(len(words) - 1):
        w1, w2 = words[i], words[i + 1]
        minLen = min(len(w1), len(w2))
        if len(w1) > len(w2) and w1[:minLen] == w2[:minLen]:
            return ""
        for j in range(minLen):
            if w1[j] != w2[j]:
                adj[w1[j]].add(w2[j])
                break

    visited: dict[str, bool] = {}  # {char: bool} False visited, True current path
    res: list[str] = []

    def dfs(char: str) -> bool:
        if char in visited:
            return visited[char]

        visited[char] = True

        for neighChar in adj[char]:
            if dfs(neighChar):
                return True

        visited[char] = False
        res.append(char)
        return False

    for char in adj:
        if dfs(char):
            return ""

    res.reverse()
    return "".join(res)
