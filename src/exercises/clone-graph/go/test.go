func buildGraph(adj [][]int) *Node {
	if len(adj) == 0 {
		return nil
	}
	nodes := make([]*Node, len(adj))
	for i := range adj {
		nodes[i] = &Node{Val: i + 1}
	}
	for i, neighbors := range adj {
		for _, nei := range neighbors {
			nodes[i].Neighbors = append(nodes[i].Neighbors, nodes[nei-1])
		}
	}
	return nodes[0]
}

func graphToAdj(node *Node) [][]int {
	if node == nil {
		return [][]int{}
	}
	visited := make(map[int]*Node)
	var dfs func(n *Node)
	dfs = func(n *Node) {
		if _, ok := visited[n.Val]; ok {
			return
		}
		visited[n.Val] = n
		for _, nei := range n.Neighbors {
			dfs(nei)
		}
	}
	dfs(node)
	adj := make([][]int, len(visited))
	for i := 1; i <= len(visited); i++ {
		if n, ok := visited[i]; ok {
			row := []int{}
			for _, nei := range n.Neighbors {
				row = append(row, nei.Val)
			}
			adj[i-1] = row
		} else {
			adj[i-1] = []int{}
		}
	}
	return adj
}

Tests.EqualCheck("Example 1", [][]int{{2}, {1, 3}, {2}}, graphToAdj(cloneGraph(buildGraph([][]int{{2}, {1, 3}, {2}}))))
Tests.EqualCheck("Example 2", [][]int{{}}, graphToAdj(cloneGraph(buildGraph([][]int{{}}))))
Tests.EqualCheck("Example 3", [][]int{}, graphToAdj(cloneGraph(buildGraph([][]int{}))))
