#include <iostream>
#include <vector>
using namespace std;

class Solution {
public :
    /**
 * 动态规划练习
 * 三角形的最小路径和
 * 使用自底向上动态规划的方式
 * 1.确定存放历史记录的数组 此题中数组里存放的是到达每一行时的路径和的最小值
 * 2.确定动态转移方程 dp[j] = min(dp[j+1] , dp[j]) + triangle[i][j];
 * 3.确定初始值 
 */
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size();
        //vector<vector<int>> dp(size + 1, vector<int>(size + 1, 0));
        vector<int> dp(size + 1, 0);
        for (int i = size - 1; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};

int main() {
    int n = 0;
    cin >> n;
    vector<vector<int>> triangle(n, vector<int>(n,0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++){
            cin >> triangle[i][j];
        }
    }
    Solution solution;
    int result = solution.minimumTotal(triangle);
    cout << result << endl;
    system("pause");
    return 0;
}