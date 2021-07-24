#include <iostream>
#include <vector>
using namespace std;

class Solution {
    static constexpr int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<bool>> visted(n, vector<bool>(n));
        vector<vector<int>> result(n, vector<int>(n));
        int total = n * n;
        int directionIndex = 0;
        int i = 0, j = 0;
        for (; i < total; ++i) {
            result[i][j] = i;
            visted[i][j] = true;
            int nextRow = i + directions[directionIndex][0];
            int nextColumn = j + directions[directionIndex][1];
            if(nextRow < 0 || nextRow >= n || nextColumn < 0 || nextColumn >= n || visted[nextRow][nextColumn]) {
                directionIndex = (directionIndex + 1);
            }
            i += directions[directionIndex][0];
            j += directions[directionIndex][1];
        }
        return result;
    }
};