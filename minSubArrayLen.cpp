#include <iostream>
#include <vector>
using namespace std;

//找到数组中和大于等于s的最短子数组
class Solution {
    int minLength = INT_MAX;
    int count = 0;

public:
    int minSubArrayLen1(int s, vector<int>& nums) {
        dfs(0, s, nums);
        return minLength == INT_MAX ? 0 : minLength;
    }

    void dfs(int i, int s, vector<int>& nums) {
        int sum = 0;
        if(i == nums.size()){
            return;
        }
        for (int index = i; index < nums.size(); i++) {
            sum += nums[i];
            count++;
            if(sum >= s){
                minLength = min(count, minLength);
                count = 0;
                break;
            }
        }
        dfs(i + 1, s, nums);
    }

    //使用前缀和加二分查找
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if(n == 0) {
            return 0;
        }

        vector<int> sum(n + 1, 0);
        for (int i = 1; i <= n; i++){
            sum[i] = sum[i - 1] + nums[i - 1];
        }

        int result = INT_MAX;
        for (int i = 1; i <= n; i++) {
            int target = s + nums[i - 1];
            auto bound = lower_bound(nums.begin(), nums.end(), target);
            if(bound != nums.end()) {
                result = min(result, static_cast<int>((bound - nums.begin()) - (i - 1)));
            }
        }
        return result == INT_MAX ? 0 : result;
    }
};