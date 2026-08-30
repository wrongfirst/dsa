void reorderList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    // 1. Find middle of list
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 2. Reverse second half
    ListNode* second = slow->next;
    slow->next = nullptr;
    ListNode* prev = nullptr;
    while (second != nullptr) {
        ListNode* tmp = second->next;
        second->next = prev;
        prev = second;
        second = tmp;
    }

    // 3. Merge two halves
    ListNode* first = head;
    second = prev;
    while (second != nullptr) {
        ListNode* tmp1 = first->next;
        ListNode* tmp2 = second->next;
        first->next = second;
        second->next = tmp1;
        first = tmp1;
        second = tmp2;
    }
}
