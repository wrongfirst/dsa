func validTree(n int, edges [][]int) bool {
    if n == 0 {
        return true
    }
    adj := make(map[int][]int)
    for i := 0; i < n; i++ {
        adj[i] = []int{}
    }
    for _, edge := range edges {
        n1, n2 := edge[0], edge[1]
        adj[n1] = append(adj[n1], n2)
        adj[n2] = append(adj[n2], n1)
    }

    visit := make(map[int]bool)

    var dfs func(i, prev int) bool
    dfs = func(i, prev int) bool {
        if visit[i] {
            return false
        }

        visit[i] = true
        for _, j := range adj[i] {
            if j == prev {
                continue
            }
            if !dfs(j, i) {
                return false
            }
        }
        return true
    }

    return dfs(0, -1) && n == len(visit)
}
