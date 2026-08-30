ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0, head);
    ListNode* left = &dummy;
    ListNode* right = head;

    while (n > 0 && right != nullptr) {
        right = right->next;
        n--;
    }

    while (right != nullptr && left != nullptr) {
        left = left->next;
        right = right->next;
    }

    if (left != nullptr && left->next != nullptr) {
        ListNode* to_delete = left->next;
        left->next = left->next->next;
        delete to_delete;
    }

    return dummy.next;
}
