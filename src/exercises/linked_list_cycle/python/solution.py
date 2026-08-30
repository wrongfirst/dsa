# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

def hasCycle(head: ListNode | None) -> bool:
    slow: ListNode | None = head
    fast: ListNode | None = head

    while fast and fast.next and slow:
        slow = slow.next
        fast = fast.next
        if fast:
            fast = fast.next
        if slow == fast:
            return True
    return False
