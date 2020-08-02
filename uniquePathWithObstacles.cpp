#include <iostream>
#include <vector>
using namespace std;

class Solution {
public :
/*动态规划练习 
 * 有障碍物的不同路径
 * 1.定义数组用于保存历史数据.此题中保存的是到(i,j)处的方法数
 * 2.状态转移方程 没有障碍物的地方 dp[i][j] = d[i - 1][j] + d[i][j - 1]
 *   有障碍物的地方 只有向下或者向右一种方法
 * 3.初始化 在目的地在第一行的时候只能向右走 目的地在第一列的时候只能向下走
 *   故dp[0][j] = 1; dp[i][0] = 1;
 */
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[1].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < obstacleGrid[i].size(); j++) {
                if(obstacleGrid[i][j] == 0) {
                    if(i == 0 && j == 0) {
                        dp[i][j] = 1;
                    }
                    else if(i == 0 && j > 0) {
                        dp[i][j] = dp[i][j - 1];
                    }
                    else if(i > 0 && j == 0) {
                        dp[i][j] = dp[i - 1][j];
                    }
                    else {
                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                    }
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[n - 1][m - 1];
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
    int result = solution.uniquePathsWithObstacles(nums);
    cout << result << endl;
    system("pause");
    return 0;
}