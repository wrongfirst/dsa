int climbStairs(int n);

int main() {
    Tests.equal_check("Example 1", 2, climbStairs(2));
    Tests.equal_check("Example 2", 3, climbStairs(3));
    Tests.equal_check("Base case 1", 1, climbStairs(1));
    return 0;
}
