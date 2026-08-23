def topKFrequent(nums: List[int], k: int) -> List[int]:
    count: Dict[int, int] = {}
    freq: List[List[int]] = [[] for i in range(len(nums) + 1)]

    for n in nums:
        count[n] = 1 + count.get(n, 0)
    for n, c in count.items():
        freq[c].append(n)

    res: List[int] = []
    for i in range(len(freq) - 1, 0, -1):
        for n in freq[i]:
            res.append(n)
            if len(res) == k:
                return res
    return res
