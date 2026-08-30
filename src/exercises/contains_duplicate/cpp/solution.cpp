#include <vector>
#include <unordered_set>

bool hasDuplicate(const std::vector<int>& nums) {
    std::unordered_set<int> seen;
    for (int num : nums) {
        if (seen.find(num) != seen.end()) {
            return true;
        }
        seen.insert(num);
    }
    return false;
}
