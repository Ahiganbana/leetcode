#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//求带有重复元素的所有子集
class Solution {
    vector<vector<int>> result;
    vector<int> tmp;

public:

    vector<vector<int>> subsetsWithDup1(vector<int>& nums) {
        //使用位运算
        //剪枝 --> 去掉子集中重复的
        int size = nums.size();
        for (int i = 0; i < (1 << size); ++i) {
            tmp.clear();
            for (int j = 0; j < size; ++j) {
                if(i & (1 << j)){
                    tmp.push_back(nums[j]);
                }
            }
            result.push_back(tmp);
        }
        return result;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(0, nums);
        return result;
    }

    void dfs(int curr, vector<int>& nums) {
        int size = nums.size();
        if(curr == size) {
            result.push_back(tmp);
            return;
        }
        for (int i = curr; i < size; ++i) {
            if(i > curr && nums[i] == nums[i - 1]) {
                continue;
            }
            tmp.push_back(nums[i]);
            dfs(i + 1, nums);
            tmp.pop_back();
        }
        dfs(curr + 1, nums);                
    }
};