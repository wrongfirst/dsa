#include <string>
#include <stack>
#include <unordered_map>

bool isValid(const std::string& s) {
    std::unordered_map<char, char> map = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
    std::stack<char> st;

    for (char c : s) {
        if (map.find(c) == map.end()) {
            st.push(c);
        } else {
            if (st.empty() || st.top() != map[c]) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}
