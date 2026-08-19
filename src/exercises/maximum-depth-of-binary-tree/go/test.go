Tests.EqualCheck("Example 1", 3, maxDepth(ListToTree([]*int{MakeInt(1), MakeInt(2), MakeInt(3), nil, nil, MakeInt(4)})))
Tests.EqualCheck("Example 2", 0, maxDepth(nil))
