class Solution {
    /*
    动态规划
    dp[i] 存放的是总和为target-nums[i]的元素组合个数
    dp[0] = 1;
    dp[i] ++ dp[i - nums[i]];
    */
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int j = 0; j < nums[i]; ++j) {
                if(nums[j] <= i) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};