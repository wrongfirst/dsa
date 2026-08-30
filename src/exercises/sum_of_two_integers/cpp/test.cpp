int getSum(int a, int b);

int main() {
    Tests.equal_check("Example 1", 2, getSum(1, 1));
    Tests.equal_check("Example 2", 11, getSum(4, 7));
    Tests.equal_check("Negative number", 1, getSum(-2, 3));
    return 0;
}
