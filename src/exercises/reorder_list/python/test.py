h1 = list_to_linked_list([2, 4, 6, 8])
reorderList(h1)
Tests.equal_check("Example 1", [2, 8, 4, 6], linked_list_to_list(h1))

h2 = list_to_linked_list([2, 4, 6, 8, 10])
reorderList(h2)
Tests.equal_check("Example 2", [2, 10, 4, 8, 6], linked_list_to_list(h2))
