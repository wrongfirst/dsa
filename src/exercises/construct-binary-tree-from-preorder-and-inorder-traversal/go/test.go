Tests.EqualCheck("Example 1", []*int{MakeInt(1), MakeInt(2), MakeInt(3), nil, nil, nil, MakeInt(4)}, TreeToList(buildTree([]int{1, 2, 3, 4}, []int{2, 1, 3, 4})))
Tests.EqualCheck("Example 2", []*int{MakeInt(1)}, TreeToList(buildTree([]int{1}, []int{1})))
