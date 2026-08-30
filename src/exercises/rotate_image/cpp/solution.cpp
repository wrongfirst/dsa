#include <vector>

void rotate(std::vector<std::vector<int>>& matrix) {
    int l = 0;
    int r = static_cast<int>(matrix.size()) - 1;

    while (l < r) {
        for (int i = 0; i < r - l; ++i) {
            int top = l;
            int bottom = r;

            int top_left = matrix[top][l + i];

            // bottom left -> top left
            matrix[top][l + i] = matrix[bottom - i][l];

            // bottom right -> bottom left
            matrix[bottom - i][l] = matrix[bottom][r - i];

            // top right -> bottom right
            matrix[bottom][r - i] = matrix[top + i][r];

            // top left -> top right
            matrix[top + i][r] = top_left;
        }
        r--;
        l++;
    }
}
