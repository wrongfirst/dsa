def hasDuplicate(nums: List[int]) -> bool:
    hashset: Set[int] = set()

    for n in nums:
        if n in hashset:
            return True
        hashset.add(n)
    return False
