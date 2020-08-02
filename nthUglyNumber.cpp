#include <iostream>
#include <vector>
using namespace std;

/**
 * 动态规划练习:找出第n个丑数(质因数只包含2,3,5的整数)
 * 1. 创建一个存放历史数据的数组,此处dp[i]中存放的是第i个丑数
 * 2. 确定初始值 : 1是丑数,dp[1] = 1;
 * 3. 确定动态转移方程 : 
 *      dp[i] = dp[i-1] + ?;
 *  */

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1, 0);
        int i2, i3, i5;
        i2 = i3 = i5 = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = min(2 * dp[i2], min(3 * dp[i3], 5 * dp[i5]));
            if (dp[i] == 2 * dp[i2]){
                i2++;
            }
            if (dp[i] == 3 * dp[i3]){
                i3++;
            }
            if (dp[i] == 5 * dp[i5]){
                i5++;
            }
        }
        return dp[n];
    }
};

int main() {
    Solution solution;
    int n;
    cin >> n;
    int result = solution.nthUglyNumber(n);
    cout << result << endl;
    system("pause");
    return 0;
}