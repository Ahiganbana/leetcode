#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /*动态规划练习
    *1. 定义数组存放历史记录,此题中数组应存放售出股票的最大利润
    *2. 确定初始值.初始值应该为0
    *3. 确定此次利润与之前利润的联系. 
    *假设当前为第i天,令minPrice表示前i-1天的最低价格;令maxProfit表示
    前i-1天的最大收益,于是有:
    *   在第i天卖出. 
    *       此时应该在前i-1天中的价值最低点买入,currProfit = prices[i] - minPrice;
    *   不在第i天卖出.
    *       此时第i天的最大收益等于前i-1天的最大收益
    * 状态转移方程:
    * maxProfit = max(在第i天卖出所得的收益, 前i-1天的最大收益);
    * */
    int maxProfit(vector<int> &prices)
    {
        int num = prices.size();
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for (int i = 0; i < num; i++) {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        return maxProfit;
    }
};

int main()
{
    Solution solution;
    vector<int> nums;
    int n = 0;
    while (n != -1)
    {
        cin >> n;
        nums.push_back(n);
    }
    nums.pop_back();
    int result = solution.maxProfit(nums);
    cout << result << endl;
    system("pause");
    return 0;
}