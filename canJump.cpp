#include <iostream>
#include <vector>
using namespace std;

//如果数组中的每一个数表示能够跳到的最远距离,问能否跳到最后
class Solution {
    bool flag = false;

public:
    //回溯法(超时)
    bool canJump1(vector<int>& nums) {
        int size = nums.size();
        if(size <= 1) {
            return true;
        }
        dfs(nums, 0);
        return flag;
    }

    void dfs(vector<int>& nums, int start) {
        if(start >= nums.size() - 1) {
            flag = true;
            return;
        }
        if(nums[start] == 0) {
            return;
        }
        for (int i = 1; i <= nums[start]; ++i) {
            int next = i + start;
            dfs(nums, next);
        }
    }

    //动态规划(超时)
    bool canJump2(vector<int>& nums) {
        int size = nums.size();
        //用于存放历史信息的数组,这里表示的是第i个位置可不可达
        vector<bool> dp;
        //dp初始胡
        dp[0] = true;
        for (int i = 1; i < size; ++i) {
            for (int j = 0; j < i; ++j) {
                if(dp[j] & j + nums[j] >= i){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[size - 1];
    }

    //贪心算法,维护一个最远可以到达的地方,如果这个地方大于等于数组长度说明数组可达
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int rightMost = 0;
        for (int i = 0; i < size; ++i) {
            if(i <= rightMost) {
                rightMost = max(rightMost, i + nums[i]);
                if(rightMost >= size - 1) {
                    return true;
                }
            }
        }
        return false;
    }
};