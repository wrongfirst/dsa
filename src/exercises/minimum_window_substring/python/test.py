Tests.equal_check("Example 1", "YXAZ", minWindow("OUZODYXAZV", "XYZ"))
Tests.equal_check("Example 2", "xyz", minWindow("xyz", "xyz"))
Tests.equal_check("Example 3", "", minWindow("x", "xy"))
