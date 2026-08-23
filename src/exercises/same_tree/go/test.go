Tests.BoolCheck("Example 1", isSameTree(IntsToTree(1, 2, 3), IntsToTree(1, 2, 3)) == true)
Tests.BoolCheck("Example 2", isSameTree(IntsToTree(4, 7), ListToTree([]*int{MakeInt(4), nil, MakeInt(7)})) == false)
Tests.BoolCheck("Example 3", isSameTree(IntsToTree(1, 2, 3), IntsToTree(1, 3, 2)) == false)
