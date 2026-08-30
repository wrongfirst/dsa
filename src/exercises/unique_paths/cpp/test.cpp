int uniquePaths(int m, int n);

int main() {
    Tests.equal_check("Example 1", 21, uniquePaths(3, 6));
    Tests.equal_check("Example 2", 6, uniquePaths(3, 3));
    Tests.equal_check("1x1 grid", 1, uniquePaths(1, 1));
    return 0;
}
