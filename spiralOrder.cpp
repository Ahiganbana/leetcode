#include <iostream>
#include <vector>

using namespace std;

//螺旋顺时针输出二维数组
class Solution {
    static constexpr int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int row = matrix.size();
        if(row == 0) {
            return result;
        }
        int colum = matrix[0].size();
        int i = 0, j = 0;
        vector<vector<bool>> visited(row, vector<bool>(colum));
        int total = row * colum;
        int directionIndex = 0;
        for (int k = 0; k < total; k++) {
            result.push_back(matrix[i][j]);
            visited[i][j] = true;
            int nextRow = i + directions[directionIndex][0];
            int nextColumn = j + directions[directionIndex][1];
            if(nextRow < 0 || nextRow >= row || nextColumn < 0 || nextColumn >= colum || visited[nextRow][nextColumn]){
                directionIndex = (directionIndex + 1) % 4;
            }
            i += directions[directionIndex][0];
            j += directions[directionIndex][1];
        }
        return result;
    }
};