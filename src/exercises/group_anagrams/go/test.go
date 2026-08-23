Tests.EqualCheck("Example 1", NormalizeNestedStrings([][]string{{"act", "cat"}, {"pots", "tops", "stop"}, {"hat"}}), NormalizeNestedStrings(groupAnagrams([]string{"act", "pots", "tops", "cat", "stop", "hat"})))
Tests.EqualCheck("Example 2", NormalizeNestedStrings([][]string{{"x"}}), NormalizeNestedStrings(groupAnagrams([]string{"x"})))

