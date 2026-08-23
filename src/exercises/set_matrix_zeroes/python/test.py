s = Solution()
m1 = [[0, 0], [0, 0]]
s.setZeroes(m1)
Tests.equal_check("Example 1", [[0, 0], [0, 0]], m1)

m2 = [[1, 0, 3], [0, 0, 0], [6, 0, 8]]
s.setZeroes(m2)
Tests.equal_check("Example 2", [[0, 0, 0], [0, 0, 0], [0, 0, 0]], m2)
