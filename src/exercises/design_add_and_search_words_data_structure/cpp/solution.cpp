#include <string>
#include <vector>

class WordDictionary {
private:
    struct Node {
        Node* children[26];
        bool is_word;
        Node() : is_word(false) {
            for (int i = 0; i < 26; ++i) children[i] = nullptr;
        }
    };

    Node* root;

    bool dfs(int j, const std::string& word, Node* cur) {
        for (int i = j; i < static_cast<int>(word.length()); ++i) {
            char c = word[i];
            if (c == '.') {
                for (int k = 0; k < 26; ++k) {
                    if (cur->children[k] != nullptr && dfs(i + 1, word, cur->children[k])) {
                        return true;
                    }
                }
                return false;
            } else {
                int idx = c - 'a';
                if (cur->children[idx] == nullptr) {
                    return false;
                }
                cur = cur->children[idx];
            }
        }
        return cur->is_word;
    }

public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(const std::string& word) {
        Node* cur = root;
        for (char c : word) {
            int idx = c - 'a';
            if (cur->children[idx] == nullptr) {
                cur->children[idx] = new Node();
            }
            cur = cur->children[idx];
        }
        cur->is_word = true;
    }

    bool search(const std::string& word) {
        return dfs(0, word, root);
    }
};
