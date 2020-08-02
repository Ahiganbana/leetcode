#include <iostream>
#include <vector>
using namespace std;

class Solution{
public :
    /*动态规划练习
    *找出路径上数字总和最小的值
    *1. 定义存放历史数据的数组.此题中存放的是到(i,j)位置时的和
    *2. 状态转移方程 dp[i][j] = min(dp[i - 1][j] + grid[i], dp[i][j - 1] + grid[i]);
    *3. 确定初始值 在第一行、第一列的位置只有向右或者向下一种走法
    *   故 dp[0][j] = dp[0][j - 1] + grid[i][j];
    *   且 dp[i][0] = dp[i - 1][0] + grid[i][j];
    */
    int minPathSum (vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        int row = grid.size();
        int cloumn = grid[0].size();
        vector<vector<int>> dp(row,vector<int>(cloumn,0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < cloumn; j++) {
                if(i == 0 && j == 0) {
                    dp[i][j] = grid[0][0];
                }
                else if(i == 0 && j > 0) {
                    dp[i][j] = dp[i][j - 1] + grid[i][j];
                }
                else if(i > 0 && j == 0) {
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                }
                else {
                    dp[i][j] = min(dp[i - 1][j] + grid[i][j], dp[i][j - 1] + grid[i][j]);
                }
            }
        }
        return dp[row - 1][cloumn - 1];
    }
};

int main() {
    int n = 0;
    int m = 0;
    int num = 0;
    cin >> n >> m;
    vector<vector<int>> nums(n,vector<int>(m,0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> num;
            nums[i][j] = num;
        }
    }
    Solution solution;
    int result = solution.minPathSum(nums);
    cout << result << endl;
    system("pause");
    return 0;
}