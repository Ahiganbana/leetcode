#include <iostream>
#include <vector>
using namespace std;

/**
 * 动态规划练习 : 含冷冻期的股票买卖问题 在卖出股票后的一天既不能买进也不能卖出.
 * 1. 确定用于存放历史记录的数组 此题中使用二维数组(n×2)其中dp[i][0] 表示第i天不持有股票 dp[i][1]表示第i天持有股票
 * 2. 确定初始值 : dp[0][0] = 0 第一天不持有股票
 *                dp[0][1] = -price[0] 第一天持有股票(买进股票)
 *                dp[1][0] = max(dp[0][0],dp[0][1] + price[1])第二天不持有股票(第一天没有股票的基础上第二天没有股票,第一天有股票第二天卖掉了)
 *                dp[1][1] = max(dp[0][0] - price[1],dp[0][1])第二天持有股票(第一天持有股票第二天没买进也没卖出,第一天没有股票第二天买进)
 * 3. 确定状态转移方程 : 
 *      第i天不持有 : 
 *      dp[i][0] = max(dp[i-1][0],dp[i-1][1] + price[i])第i天不持有股票(第i-1天不持有股票保持没有股票,第i-1天持有股票并在第i天卖出)
 *      dp[i][1] = max(dp[i-2][0] - price[i], dp[i-1][1])第i天持有股票(第i-2天没有股票第i天买进股票(冻结期),第i-1天持有股票并继续持有股票)
 * */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size == 0 || size == 1){
            return 0;
        }
        else if(size == 2){
            if(prices[0] > prices[1] || prices[0] == prices[1]){
                return 0;
            }
            else{
                return prices[1] - prices[0];
            }
        }
        vector<vector<int>> dp(size, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[1][0] = max(dp[0][0], dp[0][1] + prices[1]);
        dp[1][1] = max(dp[0][0] - prices[1], dp[0][1]);
        for (int i = 2; i < size; i++) {
            dp[i][0] = max(dp[i - 1][1] + prices[i], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 2][0] - prices[i], dp[i - 1][1]);
        }
        return dp[size - 1][0];
    }
};

int main() {
    Solution solution;
    int n;
    cin >> n;
    vector<int> input(n, 0);
    for (int i = 0; i < n; i++){
        cin >> input[i];
    }
    int result = solution.maxProfit(input);
    cout << result << endl;
    system("pause");
    return 0;
}