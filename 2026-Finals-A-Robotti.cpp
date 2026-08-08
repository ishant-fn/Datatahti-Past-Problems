#include <bits/stdc++.h>
using namespace std;

int findPaths (vector<vector<int>> &grid, int x, int y, int direction) {
        int total = 0;
        if (grid[x][y] == -2) {
            return 0;
        }
        if (direction == 1 || direction == 3) {
            direction += grid[x][y];
        } else {
            direction -= grid[x][y];
        }
        if (direction == 0) {
            direction = 4;
        }

        if (direction == 5) {
            direction = 1;
        }

        grid[x][y] *= -1;

        if (direction == 1) {
            total = findPaths(grid, x, y - 1, direction) + 1;
        } else if (direction == 2) {
            total = findPaths(grid, x + 1, y, direction) + 1;
        } else if (direction == 3) {
            total = findPaths(grid, x, y + 1, direction) + 1;
        } else if (direction == 4) {
            total = findPaths(grid, x - 1, y, direction) + 1;
        }
    return total;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string currentRow;
    vector<vector<int>> grid(n + 2, vector<int>(n + 2, -2));

    for (int y = 1; y <= n; ++y) {
        cin >> currentRow;
        for (int x = 1; x <= n; ++x) {
            if (currentRow[x - 1] == '/') {
                grid[x][y] = 1;
            } else if (currentRow[x - 1] == '\\') {
                grid[x][y] = -1;
            } else {
                grid[x][y] = 0;
            }
        }
    }

    cout << findPaths(grid, 1, 1, 3) << "\n";
}
