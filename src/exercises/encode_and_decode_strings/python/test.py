# Problem examples
Tests.equal_check("Example 1", ["Hello", "World"], decode(encode(["Hello", "World"])))
Tests.equal_check("Example 2", [""], decode(encode([""])))
Tests.equal_check("Example 2", [], decode(encode([])))

# Delimiter & length-prefix collision cases
Tests.equal_check("Delimiter in content", ["#", "##", "4#test", "10#hello#world"], decode(encode(["#", "##", "4#test", "10#hello#world"])))

# Boundary string lengths (< 200)
Tests.equal_check("Max length strings", ["a" * 199, "b" * 199], decode(encode(["a" * 199, "b" * 199])))
