Tests.equal_check("Example 1", [[2], [1, 3], [2]], graph_to_adj(cloneGraph(build_graph([[2], [1, 3], [2]]))))
Tests.equal_check("Example 2", [[]], graph_to_adj(cloneGraph(build_graph([[]]))))
Tests.equal_check("Example 3", [], graph_to_adj(cloneGraph(build_graph([]))))
