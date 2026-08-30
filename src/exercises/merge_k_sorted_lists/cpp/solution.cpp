#include <vector>
#include <queue>

struct CompareNode {
    bool operator()(const ListNode* a, const ListNode* b) const {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    std::priority_queue<ListNode*, std::vector<ListNode*>, CompareNode> pq;

    for (ListNode* head : lists) {
        if (head != nullptr) {
            pq.push(head);
        }
    }

    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (!pq.empty()) {
        ListNode* curr = pq.top();
        pq.pop();

        tail->next = curr;
        tail = tail->next;

        if (curr->next != nullptr) {
            pq.push(curr->next);
        }
    }

    return dummy.next;
}
