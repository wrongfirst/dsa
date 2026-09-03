// Problem description examples
Tests.EqualCheck("Problem Example 1", []int{1, 3, 2, 7, 6, 5, 4}, TreeToInts(invertTree(IntsToTree(1, 2, 3, 4, 5, 6, 7))))
Tests.EqualCheck("Problem Example 2", []int{3, 1, 2}, TreeToInts(invertTree(IntsToTree(3, 2, 1))))

// Single node
Tests.EqualCheck("Single node", []int{1}, TreeToInts(invertTree(IntsToTree(1))))

// Asymmetric / Skewed trees
Tests.EqualCheck("Left child only", []*int{MakeInt(1), nil, MakeInt(2)}, TreeToList(invertTree(ListToTree([]*int{MakeInt(1), MakeInt(2)}))))
Tests.EqualCheck("Right child only", []*int{MakeInt(1), MakeInt(2)}, TreeToList(invertTree(ListToTree([]*int{MakeInt(1), nil, MakeInt(2)}))))
Tests.EqualCheck("Left-skewed tree", []*int{MakeInt(1), nil, MakeInt(2), nil, MakeInt(3)}, TreeToList(invertTree(ListToTree([]*int{MakeInt(1), MakeInt(2), nil, MakeInt(3)}))))
Tests.EqualCheck("Right-skewed tree", []*int{MakeInt(1), MakeInt(2), nil, MakeInt(3)}, TreeToList(invertTree(ListToTree([]*int{MakeInt(1), nil, MakeInt(2), nil, MakeInt(3)}))))

// Negative and zero values
Tests.EqualCheck("Negative values and bounds", []int{0, 100, -100}, TreeToInts(invertTree(IntsToTree(0, -100, 100))))

// Duplicate values
Tests.EqualCheck("Duplicate values", []int{2, 2, 2}, TreeToInts(invertTree(IntsToTree(2, 2, 2))))

