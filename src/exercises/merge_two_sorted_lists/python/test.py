Tests.equal_check("Example 1", [1, 1, 2, 3, 4, 5], linked_list_to_list(mergeTwoLists(list_to_linked_list([1, 2, 4]), list_to_linked_list([1, 3, 5]))))
Tests.equal_check("Example 2", [1, 2], linked_list_to_list(mergeTwoLists(list_to_linked_list([]), list_to_linked_list([1, 2]))))
