func climbStairs(n int) int {
    if n <= 3 {
        return n
    }
    n1, n2 := 2, 3

    for i := 4; i <= n; i++ {
        temp := n1 + n2
        n1 = n2
        n2 = temp
    }
    return n2
}
