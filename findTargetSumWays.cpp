#include <iostream>
#include <vector>
using namespace std;

class Solution {
    //存放每个位置加或间的和值
    vector<int> dp;
    int res;

public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int size = nums.size();
        if(size == 0) {
            return 0;
        }
        res = 0;
        dp.resize(size + 1);
        dfs(nums, S, 0, 0);
        return res;
    }

    void dfs(vector<int>& nums, int S, int index, int tmp) {
        if(index == nums.size()) {
            if(tmp == S) {
                res++;
            }
        }else{
            dfs(nums, S, index + 1, tmp + nums[i]);
            dfs(nums, S, index, tmp - nums[i]);
        }
    }
};