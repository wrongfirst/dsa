# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

def removeNthFromEnd(head: Optional[ListNode], n: int) -> Optional[ListNode]:
    dummy = ListNode(0, head)
    left: Optional[ListNode] = dummy
    right: Optional[ListNode] = head

    while n > 0 and right:
        right = right.next
        n -= 1

    while right and left:
        left = left.next
        right = right.next

    if left and left.next:
        left.next = left.next.next
    return dummy.next
