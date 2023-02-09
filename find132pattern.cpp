#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 找132模式的数
class Solution {
public:
    // 使用单调栈结构维护2的值
    bool find132pattern(vector<int>& nums) {
        stack<int> stk;
        int n = nums.size();
        stk.push(nums[n - 1]);
        int max_k = INT_MIN;
        for (int i = n - 2; i >= 0; --i) {
            if(nums[i] < max_k) {
                return true;
            }
            while(!stk.empty() && nums[i] > stk.top()) {
                max_k = stk.top();
                stk.pop();
            }
            if(nums[i] > max_k) {
                stk.push(nums[i]);
            }
        }
        return false;
    }
};