def validTree(n: int, edges: list[list[int]]) -> bool:
    if not n:
        return True
    adj: dict[int, list[int]] = {i: [] for i in range(n)}
    for n1, n2 in edges:
        adj[n1].append(n2)
        adj[n2].append(n1)

    visit: set[int] = set()

    def dfs(i: int, prev: int) -> bool:
        if i in visit:
            return False

        visit.add(i)
        for j in adj[i]:
            if j == prev:
                continue
            if not dfs(j, i):
                return False
        return True

    return dfs(0, -1) and n == len(visit)
