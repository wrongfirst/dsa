class UnionFind:

    def __init__(self):
        self.f: dict[int, int] = {}

    def findParent(self, x: int) -> int:
        y = self.f.get(x, x)
        if x != y:
            y = self.f[x] = self.findParent(y)
        return y

    def union(self, x: int, y: int) -> None:

        self.f[self.findParent(x)] = self.findParent(y)

def countComponents(n: int, edges: list[list[int]]) -> int:
    dsu = UnionFind()
    for a, b in edges:
        dsu.union(a, b)
    return len(set(dsu.findParent(x) for x in range(n)))
