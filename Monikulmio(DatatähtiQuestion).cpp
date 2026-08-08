#include <bits/stdc++.h>
using namespace std;
 
int fill (int y, int x, vector<vector<int>> &grid) {
    if (x == -1 || y == -1 || x >= grid[0].size() || y >= grid.size()) {return 0;}
    if (grid[y][x] == 0) {
        grid[y][x] = 6;
        fill(y + 1, x, grid);
        fill(y - 1, x, grid);
        fill(y, x + 1, grid);
        fill(y, x - 1, grid);
    }
    return 0;
}
 
int drawLines (vector<vector<int>> &grid, int NumberofCorners) {
    int y;
    int x;
    int copyofX;
    int copyofY;
    pair<int, int> first_corner = {0, 0};
    pair<int, int> previous_corner = {0, 0};
    for (int i = 0; i <= NumberofCorners; ++i) {
        if (i == NumberofCorners) {
            x = first_corner.second;
            y = first_corner.first;
        } else {
            cin >> y;
            cin >> x;
            x *= 4;
            y *= 4;
        }
 
        copyofX = x;
        copyofY = y;
        
        grid[y][x] = 1;
        if (previous_corner.first != 0 && previous_corner.second != 0) {
            if (y == previous_corner.first) {
                while (x < previous_corner.second - 1) {
                    ++x;
                    grid[y][x] = -1;
                }
                while (x > previous_corner.second + 1) {
                    --x;
                    grid[y][x] = -1;
                }
            }
            if (x == previous_corner.second) {
                while (y < previous_corner.first - 1) {
                    ++y;
                    grid[y][x] = 5;
                }
                while (y > previous_corner.first + 1) {
                    --y;
                    grid[y][x] = 5;
                }
            }
            if (x > previous_corner.second) {
                while (y < previous_corner.first - 1) {
                    ++y;
                    --x;
                    grid[y][x] = 2;
                }
                while (y > previous_corner.first + 1) {
                    --y;
                    --x;
                    grid[y][x] = 3;
                }
            }
            if (x < previous_corner.second) {
                while (y < previous_corner.first - 1) {
                    ++y;
                    ++x;
                    grid[y][x] = 3;
                }
                while (y > previous_corner.first + 1) {
                    --y;
                    ++x;
                    grid[y][x] = 2;
                }
            }
        }
        previous_corner = {copyofY, copyofX};
        if (i == 0) {
            first_corner = {copyofY, copyofX};
        }
    }
    return 0;
}
 
void output (vector<vector<int>> &grid) {
    int currentChar;
    for (int i = 4; i < grid.size() - 1; i += 4) {
        for (int j = 4; j < grid[i].size() - 1; j += 4) {
            currentChar = grid[i][j];
            if (currentChar == 1) {
                cout << '*';
            } else if (currentChar == 2) {
                cout << '/';
            } else if (currentChar == 3) {
                cout << '\\';
            } else if (currentChar == -1) {
                cout << '=';
            } else if (currentChar == 5) {
                cout << '|';
            } else if (currentChar == 0) {
                cout << '#';
            } else if (currentChar == 6) {
                cout << '.';
            }
        }
        cout << "\n";
    }
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int height;
    int width;
    int NumberofCorners;
 
    cin >> height;
    cin >> width;
    cin >> NumberofCorners;

    height *= 4;
    width *= 4;

    vector<vector<int>> grid(height + 2, vector<int>(width + 2, 0));
 
    drawLines(grid, NumberofCorners);
 
    fill(0, 0, grid);
 
    fill(height + 1, width + 1, grid);
 
    output(grid);
 
    return 0;
}