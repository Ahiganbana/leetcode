#include <iostream>
#include <vector>
using namespace std;
/**
 * 动态规划练习 : 找到数组中能够组成amount的最少数量,如果不能组成返回-1
 * 1.确定用于存放历史数据的数组 此处dp[i]存放的是i能够用数组中的数组成的最小个数
 * 2.确定初始值 dp[0] = 0;
 * 3.动态转移方程
 *      i可以从i-coins[j]中转移得到 所以dp[i] = min(dp[i],dp[i-coins[j]]+1);
 * */

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0){
            return -1;
        }
        int size = coins.size();
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            int min = INT_MAX;
            for (int j = 0; j < size; j++) {
                if (i - coins[j] >= 0 && dp[i - coins[j]] < min){
                    min = dp[i - coins[j]] + 1;
                }
            }
            dp[i] = min;
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

int main() {
    Solution solution;
    int n,amount;
    cin >> n >> amount;
    vector<int> input(n, 0);
    for(int i = 0;i < n; i++) {
        cin >> input[i];
    }
    int result = solution.coinChange(input, amount);
    cout << result << endl;
    system("pause");
    return 0;
}