#include <vector>

Node* cloneGraph(Node* node);

int main() {
    Tests.equal_check("Example 1",
        std::vector<std::vector<int>>{{2}, {1, 3}, {2}},
        graph_to_adj(cloneGraph(build_graph({{2}, {1, 3}, {2}}))));

    Tests.equal_check("Example 2",
        std::vector<std::vector<int>>{{}},
        graph_to_adj(cloneGraph(build_graph({{}}))));

    Tests.equal_check("Example 3",
        std::vector<std::vector<int>>{},
        graph_to_adj(cloneGraph(build_graph({}))));

    return 0;
}
