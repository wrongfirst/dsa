#include <vector>

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);

int main() {
    Tests.equal_check("Example 1",
        std::vector<int>{1, 1, 2, 3, 4, 5},
        linked_list_to_list(mergeTwoLists(list_to_linked_list({1, 2, 4}), list_to_linked_list({1, 3, 5}))));

    Tests.equal_check("Example 2",
        std::vector<int>{1, 2},
        linked_list_to_list(mergeTwoLists(list_to_linked_list({}), list_to_linked_list({1, 2}))));

    Tests.equal_check("Both empty",
        std::vector<int>{},
        linked_list_to_list(mergeTwoLists(nullptr, nullptr)));

    return 0;
}
