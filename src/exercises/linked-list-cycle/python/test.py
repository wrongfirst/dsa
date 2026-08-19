def make_cycle(arr, pos):
    head = list_to_linked_list(arr)
    if pos == -1 or not head:
        return head
    tail = head
    target = None
    idx = 0
    while tail:
        if idx == pos:
            target = tail
        if not tail.next:
            break
        tail = tail.next
        idx += 1
    if tail and target:
        tail.next = target
    return head

s = Solution()
Tests.bool_check("Example 1", s.hasCycle(make_cycle([1, 2, 3, 4], 1)) == True)
Tests.bool_check("Example 2", s.hasCycle(make_cycle([1, 2], -1)) == False)
