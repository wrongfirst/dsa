t := ListToTree([]*int{MakeInt(5), MakeInt(3), MakeInt(8), MakeInt(1), MakeInt(4), MakeInt(7), MakeInt(9), nil, MakeInt(2)})
Tests.EqualCheck("Example 1", 5, lowestCommonAncestor(t, &TreeNode{Val: 3}, &TreeNode{Val: 8}).Val)
Tests.EqualCheck("Example 2", 3, lowestCommonAncestor(t, &TreeNode{Val: 3}, &TreeNode{Val: 4}).Val)
