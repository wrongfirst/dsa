Tests.EqualCheck("Example 1", "YXAZ", minWindow("OUZODYXAZV", "XYZ"))
Tests.EqualCheck("Example 2", "xyz", minWindow("xyz", "xyz"))
Tests.EqualCheck("Example 3", "", minWindow("x", "xy"))
