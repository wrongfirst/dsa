s = Solution()
Tests.equal_check("Example 1", [3, 2, 1, 0], linked_list_to_list(s.reverseList(list_to_linked_list([0, 1, 2, 3]))))
Tests.equal_check("Example 2", [], linked_list_to_list(s.reverseList(list_to_linked_list([]))))
