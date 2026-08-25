s := &Solution{}
Tests.EqualCheck("Example 1", []string{"Hello", "World"}, s.Decode(s.Encode([]string{"Hello", "World"})))
Tests.EqualCheck("Example 2", []string{""}, s.Decode(s.Encode([]string{""})))
