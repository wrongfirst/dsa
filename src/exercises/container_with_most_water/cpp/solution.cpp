#include <vector>
#include <algorithm>

int maxArea(const std::vector<int>& heights) {
    int l = 0;
    int r = static_cast<int>(heights.size()) - 1;
    int res = 0;

    while (l < r) {
        int area = std::min(heights[l], heights[r]) * (r - l);
        res = std::max(res, area);
        if (heights[l] < heights[r]) {
            l++;
        } else {
            r--;
        }
    }
    return res;
}
