def hasDuplicate(nums: list[int]) -> bool:
    hashset: set[int] = set()

    for n in nums:
        if n in hashset:
            return True
        hashset.add(n)
    return False
