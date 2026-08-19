type UnionFind struct {
    f map[int]int
}

func NewUnionFind() *UnionFind {
    return &UnionFind{
        f: make(map[int]int),
    }
}

func (this *UnionFind) FindParent(x int) int {
    y, exists := this.f[x]
    if !exists {
        y = x
    }
    if x != y {
        y = this.FindParent(y)
        this.f[x] = y
    }
    return y
}

func (this *UnionFind) Union(x, y int) {
    this.f[this.FindParent(x)] = this.FindParent(y)
}

func countComponents(n int, edges [][]int) int {
    dsu := NewUnionFind()
    for _, edge := range edges {
        a, b := edge[0], edge[1]
        dsu.Union(a, b)
    }

    parents := make(map[int]bool)
    for x := 0; x < n; x++ {
        parents[dsu.FindParent(x)] = true
    }
    return len(parents)
}
