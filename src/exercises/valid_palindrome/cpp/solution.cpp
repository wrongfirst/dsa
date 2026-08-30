#include <string>
#include <cctype>

bool isPalindrome(const std::string& s) {
    int l = 0;
    int r = static_cast<int>(s.length()) - 1;

    while (l < r) {
        while (l < r && !std::isalnum(static_cast<unsigned char>(s[l]))) {
            l++;
        }
        while (r > l && !std::isalnum(static_cast<unsigned char>(s[r]))) {
            r--;
        }
        if (std::tolower(static_cast<unsigned char>(s[l])) != std::tolower(static_cast<unsigned char>(s[r]))) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}
