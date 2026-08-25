
def rob(nums: list[int]) -> int:
    return max(nums[0], helper(nums[1:]), helper(nums[:-1]))

def helper(nums: list[int]) -> int:
    rob1, rob2 = 0, 0

    for n in nums:
        newRob = max(rob1 + n, rob2)
        rob1 = rob2
        rob2 = newRob
    return rob2
