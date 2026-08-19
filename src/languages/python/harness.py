from typing import List, Dict, Optional, Tuple, Set, Any
import collections
from collections import defaultdict, deque
import heapq
import math

class ListNode:
    def __init__(self, val: int = 0, next: Optional['ListNode'] = None):
        self.val = val
        self.next = next

    def __repr__(self):
        return f"ListNode({self.val})"

class TreeNode:
    def __init__(self, val: int = 0, left: Optional['TreeNode'] = None, right: Optional['TreeNode'] = None):
        self.val = val
        self.left = left
        self.right = right

    def __repr__(self):
        return f"TreeNode({self.val})"

class Node:
    def __init__(self, val: int = 0, neighbors: Optional[List['Node']] = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

    def __repr__(self):
        return f"Node({self.val})"

class Interval:
    def __init__(self, start: int = 0, end: int = 0):
        self.start = start
        self.end = end

    def __repr__(self):
        return f"Interval({self.start}, {self.end})"


def list_to_linked_list(arr: List[int]) -> Optional[ListNode]:
    if not arr:
        return None
    head = ListNode(arr[0])
    curr = head
    for v in arr[1:]:
        curr.next = ListNode(v)
        curr = curr.next
    return head

def linked_list_to_list(head: Optional[ListNode]) -> List[int]:
    res = []
    curr = head
    seen = set()
    while curr:
        if id(curr) in seen:
            break
        seen.add(id(curr))
        res.append(curr.val)
        curr = curr.next
    return res

def list_to_tree(arr: List[Optional[int]]) -> Optional[TreeNode]:
    if not arr or arr[0] is None:
        return None
    root = TreeNode(arr[0])
    queue = collections.deque([root])
    i = 1
    while queue and i < len(arr):
        node = queue.popleft()
        if i < len(arr) and arr[i] is not None:
            node.left = TreeNode(arr[i])
            queue.append(node.left)
        i += 1
        if i < len(arr) and arr[i] is not None:
            node.right = TreeNode(arr[i])
            queue.append(node.right)
        i += 1
    return root

def tree_to_list(root: Optional[TreeNode]) -> List[Optional[int]]:
    if not root:
        return []
    res: List[Optional[int]] = []
    queue = collections.deque([root])
    while queue:
        node = queue.popleft()
        if node:
            res.append(node.val)
            queue.append(node.left)
            queue.append(node.right)
        else:
            res.append(None)
    while res and res[-1] is None:
        res.pop()
    return res

class Tests:
    @staticmethod
    def bool_check(msg: str, b: bool):
        if b:
            print(f"Test passed: {msg}")
        else:
            print(f"Test failed: {msg}")
            raise Exception(f"Test failed: {msg}")

    @staticmethod
    def equal_check(msg: str, expected, actual):
        if expected == actual:
            print(f"Test passed: {msg}")
        else:
            print(f"Test failed: {msg}\nExpected: {repr(expected)}\nActual:   {repr(actual)}")
            raise Exception(f"Test failed: {msg}")

