def normalize(coords):
    return sorted(coords)

s = Solution()
h1 = [[4, 2, 7, 3, 4], [7, 4, 6, 4, 7], [6, 3, 5, 3, 6]]
Tests.equal_check("Example 1", normalize([[0, 2], [0, 4], [1, 0], [1, 1], [1, 2], [1, 3], [1, 4], [2, 0]]), normalize(s.pacificAtlantic(h1)))
h2 = [[1], [1]]
Tests.equal_check("Example 2", normalize([[0, 0], [1, 0]]), normalize(s.pacificAtlantic(h2)))
