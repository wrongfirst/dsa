#include <vector>

ListNode* reverseList(ListNode* head);

int main() {
    Tests.equal_check("Example 1",
        std::vector<int>{3, 2, 1, 0},
        linked_list_to_list(reverseList(list_to_linked_list({0, 1, 2, 3}))));

    Tests.equal_check("Example 2",
        std::vector<int>{},
        linked_list_to_list(reverseList(list_to_linked_list({}))));

    return 0;
}
