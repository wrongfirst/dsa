def missingNumber(nums: List[int]) -> int:
    res = len(nums)

    for i in range(len(nums)):
        res += i - nums[i]
    return res
