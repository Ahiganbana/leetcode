#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 动态规划练习 : 找出无序序列中最长升序列的长度.
 * 1.创建数组,用于保存历史记录.此处保存的是目前升序列最长的长度.
 * 2.确定初始化的值,如果数组长度不为0,则dp[0]-1;
 * 3.确定动态转移方程 : 
 *      设置i,j两个指针,i作为输入序列的子序列,j表示子序列中的序列.
 *      如果说dp[i]要与之前的dp[j]产生联系,则表示nums[j]要大于dp[j]的最后一个数
 *      if(num[j] < nums[i]){
 *          dp[i] = max(count,dp[j]);
 *      }
 *              
 * */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if(size == 0){
            return 0;
        }
        //int count = 1;
        vector<int> dp(size,0);
        dp[0] = 1;
        for (int i = 1; i < size; i++) {
            int maxval = 0;
            for (int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    maxval = max(maxval, dp[j]);
                }
            }
            dp[i] = maxval + 1;
            //count = max(count, dp[i]);
        }

        return *max_element(dp.begin(),dp.end());
    }
};

int main() {
    int n = 0;
    Solution solution;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int result = solution.lengthOfLIS(nums);
    cout << result << endl;
    system("pause");
    return 0;
}