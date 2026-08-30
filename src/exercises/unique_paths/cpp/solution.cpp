#include <vector>

int uniquePaths(int m, int n) {
    std::vector<int> row(n, 1);

    for (int i = 0; i < m - 1; ++i) {
        std::vector<int> new_row(n, 1);
        for (int j = n - 2; j >= 0; --j) {
            new_row[j] = new_row[j + 1] + row[j];
        }
        row = new_row;
    }

    return row[0];
}
