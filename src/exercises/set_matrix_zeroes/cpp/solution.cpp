#include <vector>

void setZeroes(std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size();
    if (rows == 0) return;
    int cols = matrix[0].size();

    bool row_zero = false;

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (matrix[r][c] == 0) {
                matrix[0][c] = 0;
                if (r > 0) {
                    matrix[r][0] = 0;
                } else {
                    row_zero = true;
                }
            }
        }
    }

    for (int r = 1; r < rows; ++r) {
        for (int c = 1; c < cols; ++c) {
            if (matrix[0][c] == 0 || matrix[r][0] == 0) {
                matrix[r][c] = 0;
            }
        }
    }

    if (matrix[0][0] == 0) {
        for (int r = 0; r < rows; ++r) {
            matrix[r][0] = 0;
        }
    }

    if (row_zero) {
        for (int c = 0; c < cols; ++c) {
            matrix[0][c] = 0;
        }
    }
}
