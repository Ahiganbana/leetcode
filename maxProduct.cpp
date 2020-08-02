#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 动态规划练习 : 最大连续子数组的乘积
 * 1. 创建一个用于存放结果的数组,此时存放的是子数组的乘积
 * 2. 确定初始值,对于乘积来说,数组初始化为1
 * 3.确定动态转移方程 dp[i] = max(dp[i-1],dp[i-1]*nums[i])
 * */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        vector<int> dpMax(nums), dpMin(nums);
        for (int i = 1; i < size; ++i){
            dpMax[i] = max(dpMax[i - 1] * nums[i], max(nums[i], dpMin[i - 1] * nums[i]));
            dpMin[i] = min(dpMin[i - 1] * nums[i], min(nums[i], dpMax[i - 1] * nums[i]));
        }
        return *max_element(dpMax.begin(),dpMax.end());
    }
};

int main() {
    Solution solution;
    int n;
    cin >> n;
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        cin >> dp[i];
    }
    int result = solution.maxProduct(dp);
    cout << result << endl;
    system("pause");
    return 0;
}