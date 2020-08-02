#include <iostream>
#include <vector>
using namespace std;

/**
 * 动态规划练习 : 打家劫舍1的升级版, 添加要求所有房屋均围成一圈,故不能偷第一家与最后一家
 * 1.创建一个数组用于存放历史数据 此处存放的是偷的的钱财
 * 2.确定初始值刚开始没有开始偷dp[0] = 0;
 * 3.确定动态转移方程 : 
 *      dp[i] = max(dp[i-1],dp[i-2] + nums[i]);
 * 题目中要求第一间和最后一间相邻,可以将问题转换为第一间和最后一间不能同时偷
 * 分两种情况讨论,一种是偷第一间,另一种是偷最后一间.
 * */
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 0){
            return 0;
        }

        if(size == 1){
            return nums[0];
        }

        vector<int> dp1(size + 1,0), dp2(size + 1,0);
        dp1[1] = nums[0];
        dp2[1] = nums[1];

        for (int i = 2; i <= size - 1; i++) {
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i - 1]);
        }

        for (int i = 2; i < size; i++) {
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i]);
        }

            return max(dp1[size - 1],dp2[size - 1]);
    }
};

int main() {
    Solution solution;
    int n = 0;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    int result = solution.rob(num);
    cout << result << endl;
    system("pause");
    return 0;
}