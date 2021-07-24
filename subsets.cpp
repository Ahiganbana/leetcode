#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//找出集合中的子集
class Solution {
    vector<vector<int>> result;
    vector<int> tmp;

public:
    //二进制枚举法
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0; i < (1 << size); ++i) {
            tmp.clear();
            for (int j = 0; j < size; ++j) {
                if(i & (1 << j)) {
                    tmp.push_back(nums[j]);
                }
            }
            result.push_back(tmp);
        }
        return result;
    }

    //回溯法(递归实现的DFS)
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return result;
    }

    void dfs(int curr, vector<int>& nums) {
        if(curr == nums.size()){
            result.push_back(tmp);
            return;
        }
        tmp.push_back(nums[curr]);
        dfs(curr + 1, nums);
        tmp.pop_back();
        dfs(curr + 1, nums);
    }
};
