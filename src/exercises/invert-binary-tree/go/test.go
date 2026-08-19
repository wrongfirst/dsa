Tests.EqualCheck("Example 1", []int{4, 7, 2, 9, 6, 3, 1}, TreeToInts(invertTree(IntsToTree(4, 2, 7, 1, 3, 6, 9))))
Tests.EqualCheck("Example 2", []int{2, 3, 1}, TreeToInts(invertTree(IntsToTree(2, 1, 3))))
Tests.EqualCheck("Example 3", []int{}, TreeToInts(invertTree(IntsToTree())))
