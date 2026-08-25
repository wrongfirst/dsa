def canFinish(numCourses: int, prerequisites: list[list[int]]) -> bool:
    preMap: dict[int, list[int]] = {i: [] for i in range(numCourses)}

    for crs, pre in prerequisites:
        preMap[crs].append(pre)

    visiting: set[int] = set()

    def dfs(crs: int) -> bool:
        if crs in visiting:
            return False
        if preMap[crs] == []:
            return True

        visiting.add(crs)
        for pre in preMap[crs]:
            if not dfs(pre):
                return False
        visiting.remove(crs)
        preMap[crs] = []
        return True

    for c in range(numCourses):
        if not dfs(c):
            return False
    return True
