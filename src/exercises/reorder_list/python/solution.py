# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

def reorderList(head: Optional[ListNode]) -> None:
    if not head or not head.next:
        return

    slow: Optional[ListNode] = head
    fast: Optional[ListNode] = head.next
    while fast and fast.next and slow:
        slow = slow.next
        fast = fast.next
        if fast:
            fast = fast.next

    if not slow:
        return
    second = slow.next
    slow.next = None
    prev: Optional[ListNode] = None
    while second:
        tmp = second.next
        second.next = prev
        prev = second
        second = tmp

    first: Optional[ListNode] = head
    second = prev
    while first and second:
        tmp1 = first.next
        tmp2 = second.next
        first.next = second
        second.next = tmp1
        first = tmp1
        second = tmp2
