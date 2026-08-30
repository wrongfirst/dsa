#include <vector>

ListNode* removeNthFromEnd(ListNode* head, int n);

int main() {
    Tests.equal_check("Example 1",
        std::vector<int>{1, 2, 4},
        linked_list_to_list(removeNthFromEnd(list_to_linked_list({1, 2, 3, 4}), 2)));

    Tests.equal_check("Example 2",
        std::vector<int>{},
        linked_list_to_list(removeNthFromEnd(list_to_linked_list({5}), 1)));

    return 0;
}
