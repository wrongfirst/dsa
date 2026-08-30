#include <string>

int main() {
    PrefixTree trie;
    trie.insert("apple");
    Tests.bool_check("search apple", trie.search("apple") == true);
    Tests.bool_check("search app", trie.search("app") == false);
    Tests.bool_check("startsWith app", trie.startsWith("app") == true);
    trie.insert("app");
    Tests.bool_check("search app 2", trie.search("app") == true);
    return 0;
}
