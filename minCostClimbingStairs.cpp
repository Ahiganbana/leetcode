#include <iostream>
#include <vector>
using namespace std;

class Solution {
public :
/*动态规划练习
*1.定义存放历史变量的数组,此题中数组里存放的是 站在第i级楼梯上所需要的花费
*2.确定动态转移方程 : 到达楼顶的方式有两种:
*  ① 从倒数第一级楼梯上来  此时所需要的花费dp[i] = dp[i-1] + cost[i]
*  ② 从倒数第二级楼梯上来  此时所需要的花费dp[i] = dp[i-2] + cost[i]
*3.确定初始值: 第0级台阶和第一级台阶均为初始值 dp[0] = cost[0], dp[1] = cost[1]
*/
    int minCostClimbingStairs(vector<int>& cost) {
        int num = cost.size();
        if(num == 0 || num == 1) {
            return 0;
        }
        vector<int> dp(num + 1,0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < num; i++) {
            dp[i] = min(dp[i - 1] + cost[i], dp[i - 2] + cost[i]);
        }
        return min(dp[num - 1],dp[num - 2]);
    }
};

int main() {
    Solution solution;
    int n = 0;
    vector<int> nums;
    while(n != -100) {
        cin >> n;
        nums.push_back(n);
    }
    nums.pop_back();
    int result = solution.minCostClimbingStairs(nums);
    cout << result << endl;
    system("pause");
    return 0;
}