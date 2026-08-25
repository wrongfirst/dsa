Tests.equal_check("Example 1", [1, 1, 2, 3, 3, 4, 5, 6], linked_list_to_list(mergeKLists([list_to_linked_list([1, 2, 4]), list_to_linked_list([1, 3, 5]), list_to_linked_list([3, 6])])))
Tests.equal_check("Example 2", [], linked_list_to_list(mergeKLists([])))
Tests.equal_check("Example 3", [], linked_list_to_list(mergeKLists([list_to_linked_list([])])))
