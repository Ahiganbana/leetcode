#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//  找到数组中左边比K大 右边比K小的数 K
vector<int> findK(vector<int> nums) {
    stack<int> stk;
    int maxVal = INT_MIN;
    for (int i = 0; i < nums.size(); ++i) {
        if(nums[i] > maxVal) {
            stk.push(nums[i]);
            maxVal = nums[i];
        }else {
            while(!stk.empty() && stk.top() >= nums[i]) {
                stk.pop();
            }
        }
    }
    vector<int> res;
    while(!stk.empty()) {
        res.push_back(stk.top());
        stk.pop();
    }
    return res;
}