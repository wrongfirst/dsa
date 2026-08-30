#include <vector>

ListNode* mergeKLists(std::vector<ListNode*>& lists);

int main() {
    std::vector<ListNode*> l1 = {
        list_to_linked_list({1, 2, 4}),
        list_to_linked_list({1, 3, 5}),
        list_to_linked_list({3, 6})
    };
    Tests.equal_check("Example 1",
        std::vector<int>{1, 1, 2, 3, 3, 4, 5, 6},
        linked_list_to_list(mergeKLists(l1)));

    std::vector<ListNode*> l2 = {};
    Tests.equal_check("Example 2",
        std::vector<int>{},
        linked_list_to_list(mergeKLists(l2)));

    std::vector<ListNode*> l3 = {list_to_linked_list({})};
    Tests.equal_check("Example 3",
        std::vector<int>{},
        linked_list_to_list(mergeKLists(l3)));

    return 0;
}
