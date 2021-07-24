#include<iostream>
#include<vector>
using namespace std;

//计算 最少多少次跳跃能够到达数组的最后一个位置
/***
 * 可以使用动态规划, 需要维护两个数组,一个是dp数组,维护到第i个位置需要的最小跳数 另一个是维护从当前位置出发可以到达的最远的位置
 * 初始化: 从第0个位置出发能够跳到的最远位置为nums[0], step[1] = nums[0], dp[0] = 0
 * 转移方程 : 如果从前一个格子出发能够到达的最远距离大于当前位置,则通过前一个位置也能够到达当前位置.如果不能到达说明需要再多走一步
 *              dp[i] = step[dp[i-1]] >= i ? dp[i - 1] : dp[i - 1] + 1;
 *              step[dp[i] + 1] = max(step[dp[i] + 1], i+ nums[i]);
 * */
class Solution {
public:
    int jump(vector<int>& nums) {
        int t = nums.size();
        vector<int> dp(t, 0);
        vector<int> step(t, 0);
        if(t == 1) {
            return 0;
        }
        step[1] = nums[0];
        for (int i = 1; i < t; ++i) {
            //如果从前一个位置出发,能够到达的距离比当前距离远,说明从前一个位置出发也能够到达当前位置.
            //否则需要多走一步
            dp[i] = step[dp[i - 1]] >= i ? dp[i - 1] : dp[i - 1] + 1;
            if(dp[i] + 1 < t) {
                //计算从当前位置出发再走一步能够到达的最远位置
                step[dp[i + 1]] = max(step[dp[i] + 1], i + nums[i]);
            }
        }
        return dp[t - 1];
    }
};