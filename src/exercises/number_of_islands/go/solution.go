func numIslands(grid [][]byte) int {
    if len(grid) == 0 || len(grid[0]) == 0 {
        return 0
    }
    islands := 0
    visit := make(map[[2]int]bool)
    rows, cols := len(grid), len(grid[0])

    var dfs func(r, c int)
    dfs = func(r, c int) {
        if r < 0 || r >= rows ||
            c < 0 || c >= cols ||
            grid[r][c] == '0' ||
            visit[[2]int{r, c}] {
            return
        }
        visit[[2]int{r, c}] = true
        directions := [][2]int{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}
        for _, dir := range directions {
            dr, dc := dir[0], dir[1]
            dfs(r+dr, c+dc)
        }
    }

    for r := 0; r < rows; r++ {
        for c := 0; c < cols; c++ {
            if grid[r][c] == '1' && !visit[[2]int{r, c}] {
                islands++
                dfs(r, c)
            }
        }
    }

    return islands
}
