#include <unordered_map>

static Node* dfs(Node* curr, std::unordered_map<Node*, Node*>& old_to_new) {
    if (curr == nullptr) return nullptr;
    if (old_to_new.find(curr) != old_to_new.end()) {
        return old_to_new[curr];
    }

    Node* copy = new Node(curr->val);
    old_to_new[curr] = copy;
    for (Node* nei : curr->neighbors) {
        copy->neighbors.push_back(dfs(nei, old_to_new));
    }
    return copy;
}

Node* cloneGraph(Node* node) {
    if (node == nullptr) return nullptr;
    std::unordered_map<Node*, Node*> old_to_new;
    return dfs(node, old_to_new);
}
