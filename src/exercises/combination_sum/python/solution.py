def combinationSum(nums: list[int], target: int) -> list[list[int]]:
    res: list[list[int]] = []

    def dfs(i: int, cur: list[int], total: int) -> None:
        if total == target:
            res.append(cur.copy())
            return
        if i >= len(nums) or total > target:
            return

        cur.append(nums[i])
        dfs(i, cur, total + nums[i])
        cur.pop()
        dfs(i + 1, cur, total)

    dfs(0, [], 0)
    return res
