#include <string>

class PrefixTree {
private:
    struct Node {
        Node* children[26];
        bool is_end;
        Node() : is_end(false) {
            for (int i = 0; i < 26; ++i) children[i] = nullptr;
        }
    };

    Node* root;

public:
    PrefixTree() {
        root = new Node();
    }

    void insert(const std::string& word) {
        Node* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new Node();
            }
            curr = curr->children[idx];
        }
        curr->is_end = true;
    }

    bool search(const std::string& word) {
        Node* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                return false;
            }
            curr = curr->children[idx];
        }
        return curr->is_end;
    }

    bool startsWith(const std::string& prefix) {
        Node* curr = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                return false;
            }
            curr = curr->children[idx];
        }
        return true;
    }
};
