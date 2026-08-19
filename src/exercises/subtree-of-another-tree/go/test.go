Tests.BoolCheck("Example 1", isSubtree(IntsToTree(1, 2, 3, 4, 5), IntsToTree(2, 4, 5)) == true)
Tests.BoolCheck("Example 2", isSubtree(ListToTree([]*int{MakeInt(1), MakeInt(2), MakeInt(3), MakeInt(4), MakeInt(5), nil, nil, MakeInt(6)}), IntsToTree(2, 4, 5)) == false)
