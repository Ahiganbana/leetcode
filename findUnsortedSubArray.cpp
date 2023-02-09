// 找到数组中最短的序列,满足: 如果对这个序列排序就会使整个数组有序
// 单调栈结构 维护一个从栈底到栈顶递增的栈,保证栈顶元素始终是当前栈中的最大值
// 遍历到nums[i]如果小于当前的栈顶元素,说明需要排序更新右边界i
// 从i出发向前找最远的左边界,即从栈中弹出元素一直到nums[i] > 栈顶,

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> stk;
        int left = 0;
        int right = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if(!stk.empty() && nums[stk.top()] > nums[i]) {
                int maxVal = stk.top();
                right = max(right, i);
                while(!stk.empty() && nums[stk.top()] > nums[i]) {
                    left = min(left, stk.top());
                    stk.pop();
                }
                stk.push(maxVal);
            }else {
                stk.push(i);
            }
        }
        return left < right ? right - left + 1 : 0;
    }
};