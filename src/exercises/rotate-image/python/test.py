s = Solution()
m1 = [[3, 1], [4, 2]]
s.rotate(m1)
Tests.equal_check("Example 1", [[4, 3], [2, 1]], m1)

m2 = [[7, 4, 1], [8, 5, 2], [9, 6, 3]]
s.rotate(m2)
Tests.equal_check("Example 2", [[9, 8, 7], [6, 5, 4], [3, 2, 1]], m2)
