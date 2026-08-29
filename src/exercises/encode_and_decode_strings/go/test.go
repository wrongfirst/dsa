s := &Solution{}

// Problem examples
Tests.EqualCheck("Example 1", []string{"Hello", "World"}, s.Decode(s.Encode([]string{"Hello", "World"})))
Tests.EqualCheck("Example 2", []string{""}, s.Decode(s.Encode([]string{""})))
Tests.EqualCheck("Example 3", []string{}, s.Decode(s.Encode([]string{})))

// Delimiter & length-prefix collision cases
Tests.EqualCheck("Delimiter in content", []string{"#", "##", "4#test", "10#hello#world"}, s.Decode(s.Encode([]string{"#", "##", "4#test", "10#hello#world"})))

// Boundary string lengths (< 200)
Tests.EqualCheck("Max length strings", []string{strings.Repeat("a", 199), strings.Repeat("b", 199)}, s.Decode(s.Encode([]string{strings.Repeat("a", 199), strings.Repeat("b", 199)})))
