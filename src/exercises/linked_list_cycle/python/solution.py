# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

def hasCycle(head: Optional[ListNode]) -> bool:
    slow: Optional[ListNode] = head
    fast: Optional[ListNode] = head

    while fast and fast.next and slow:
        slow = slow.next
        fast = fast.next
        if fast:
            fast = fast.next
        if slow == fast:
            return True
    return False
