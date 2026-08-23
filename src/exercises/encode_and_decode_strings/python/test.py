Tests.equal_check("Example 1", ["Hello", "World"], decode(encode(["Hello", "World"])))
Tests.equal_check("Example 2", [""], decode(encode([""])))
