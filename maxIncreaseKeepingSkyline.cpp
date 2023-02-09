#include <iostream>
#include <vector>
using namespace std;

// 能够增高的最高高度是行和列上最大值的最小值
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int row = grid.size();
        if(row == 0) {
            return 0;
        }
        int col = grid[0].size();
        vector<vector<int>> maxNum(row, vector<int>(col, 0));
        vector<int> rowMax;
        vector<int> colMax;
        int ans = 0;
        for (int i = 0; i < row; ++i) {
            int val = *max_element(grid[i].begin(), grid[i].end());
            rowMax.push_back(val);
        }
        for (int i = 0; i < col; ++i) {
            int tmp = 0;
            for (int j = 0; j < row; ++j) {
                tmp = max(tmp, grid[j][i]);
            }
            colMax.push_back(tmp);
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                maxNum[i][j] = min(rowMax[i], colMax[j]);
                ans += maxNum[i][j] - grid[i][j];
            }
        }
        return ans;
    }
};