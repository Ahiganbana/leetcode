#include <iostream>
#include <vector>
using namespace std;

class Solution {
public :
    /*动态规划练习
    *1.定义用于存放历史记录的数组 
    此题中使用二维数组,i表示横坐标,j表示纵坐标.
    *2.状态转移方程 : 要到达(i,j)坐标有两种方式,一种是从上一格向下
    走一步到达目标,一种是从左边一格向右走一步到达目标 
    dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
    *3.确定初始值 
    *要到达第一行的某一列时,只有向右走一种走法
    *故 dp[0][j] = 1
    *同理,要到达第一列的某一行时,只有向下走一种走法
    *故 dp[i][0] = 1
    */
    int uniquePaths(int m, int n) {
        //m为列数 n为行数
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(i == 0 && j == 0) {
                    dp[i][j] = 0;
                }
                else if(i == 0 && j > 0) {
                    dp[i][j] = 1;
                }
                else if(i > 0 && j == 0) {
                    dp[i][j] = 1;
                }
                else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[n - 1][m - 1];
    }
 };

int main () {
    Solution solution;
    int m, n;
    cin >> m >> n;
    int result = solution.uniquePaths(m, n);
    cout << result << endl;
    system("pause");
    return 0;
}