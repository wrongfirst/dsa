#include <string>

int main() {
    WordDictionary d;
    d.addWord("day");
    d.addWord("bay");
    d.addWord("may");
    d.addWord("say");

    Tests.bool_check("search day", d.search("day") == true);
    Tests.bool_check("search .ay", d.search(".ay") == true);
    Tests.bool_check("search b..", d.search("b..") == true);
    Tests.bool_check("search nope", d.search("nope") == false);

    return 0;
}
