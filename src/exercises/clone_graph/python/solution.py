"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

def cloneGraph(node: Optional['Node']) -> Optional['Node']:
    oldToNew: Dict[Node, Node] = {}

    def dfs(curr_node: Node) -> Node:
        if curr_node in oldToNew:
            return oldToNew[curr_node]

        copy = Node(curr_node.val)
        oldToNew[curr_node] = copy
        for nei in (curr_node.neighbors or []):
            copy.neighbors.append(dfs(nei))
        return copy

    return dfs(node) if node else None
