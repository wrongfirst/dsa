bool hasCycle(ListNode* head);

int main() {
    Tests.bool_check("Example 1", hasCycle(make_cycle({1, 2, 3, 4}, 1)) == true);
    Tests.bool_check("Example 2", hasCycle(make_cycle({1, 2}, -1)) == false);
    Tests.bool_check("Empty list", hasCycle(nullptr) == false);
    return 0;
}
