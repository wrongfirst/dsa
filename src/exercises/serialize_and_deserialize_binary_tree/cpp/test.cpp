#include <string>
#include <vector>
#include <optional>

int main() {
    Codec codec;
    TreeNode* t1 = list_to_tree({1, 2, 3, std::nullopt, std::nullopt, 4, 5});
    Tests.equal_check("Example 1",
        tree_to_list(t1),
        tree_to_list(codec.deserialize(codec.serialize(t1))));

    TreeNode* t2 = list_to_tree({});
    Tests.equal_check("Example 2",
        std::vector<std::optional<int>>{},
        tree_to_list(codec.deserialize(codec.serialize(t2))));

    return 0;
}
