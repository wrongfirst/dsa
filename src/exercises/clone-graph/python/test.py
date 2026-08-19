def build_graph(adj):
    if not adj:
        return None
    nodes = [Node(i + 1) for i in range(len(adj))]
    for i, neighbors in enumerate(adj):
        for nei in neighbors:
            nodes[i].neighbors.append(nodes[nei - 1])
    return nodes[0]

def graph_to_adj(node):
    if not node:
        return []
    visited = {}
    def dfs(n):
        if n.val in visited:
            return
        visited[n.val] = n
        for nei in n.neighbors:
            dfs(nei)
    dfs(node)
    adj = []
    for i in range(1, len(visited) + 1):
        if i in visited:
            adj.append([nei.val for nei in visited[i].neighbors])
        else:
            adj.append([])
    return adj

s = Solution()
Tests.equal_check("Example 1", [[2], [1, 3], [2]], graph_to_adj(s.cloneGraph(build_graph([[2], [1, 3], [2]]))))
Tests.equal_check("Example 2", [[]], graph_to_adj(s.cloneGraph(build_graph([[]]))))
Tests.equal_check("Example 3", [], graph_to_adj(s.cloneGraph(build_graph([]))))
