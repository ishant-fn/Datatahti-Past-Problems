#include <bits/stdc++.h>
using namespace std;

int Search (const vector<vector<char>> &grid, pair<int, int> startPos, pair<int, int> endPos) {
    vector<vector<bool>> VisitedSquares(grid.size() + 1, vector<bool>(grid[0].size() + 1, true));
    queue<pair<pair<int, int>, int>> prevMoves;

    VisitedSquares[startPos.first][startPos.second] = false;
    prevMoves.push({startPos, 0});

    int TotalAmountOfMoves = 0;
    int StartX = startPos.second;
    int StartY = startPos.first;
    pair<int, int> currentPos = startPos;

    while (!(prevMoves.empty())) {
        StartX = prevMoves.front().first.second;
        StartY = prevMoves.front().first.first;
        currentPos = prevMoves.front().first;
        TotalAmountOfMoves = prevMoves.front().second;
        prevMoves.pop();
        if (endPos == currentPos) {
            return TotalAmountOfMoves;
        }

        for (int y = 1; y < grid.size(); ++y) {
            if (grid[y][StartX] == '.' && VisitedSquares[y][StartX]) {
                VisitedSquares[y][StartX] = false;
                prevMoves.push({{y, StartX}, TotalAmountOfMoves + 1});
            }
        }
        for (int x = 1; x < grid[0].size(); ++x) {
            if (grid[StartY][x] == '.' && VisitedSquares[StartY][x]) {
                VisitedSquares[StartY][x] = false;
                prevMoves.push({{StartY, x}, TotalAmountOfMoves + 1});
            }
        }
    }
    return -1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int height;
    int width;
    char currentChar;
    int StartX;
    int StartY;
    int EndX;
    int EndY;
    int number_of_queries;

    cin >> height >> width >> number_of_queries;

    vector<vector<char>> grid(height + 1, vector<char>(width + 1, '.'));

    for (int y = 1; y <= height; ++y) {
        for (int x = 1; x <= width; ++x) {
            cin >> currentChar;
            if (currentChar != '.') {
                grid[y][x] = currentChar;
            }
        }
    }

    for (int x = 0; x < number_of_queries; ++x) {
        cin >> StartY >> StartX;
        cin >> EndY >> EndX;
        cout << Search(grid, {StartY, StartX}, {EndY, EndX}) << "\n";
    }

    return 0;
}