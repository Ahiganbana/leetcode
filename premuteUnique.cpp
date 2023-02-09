#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        process(nums, 0);
        return res;
    }

    void process(vector<int> &nums, int i) {
        if(i == nums.size()) {
            res.push_back(nums);
            return;
        }

        int currnum = nums[i];
        for(int j = i; j < nums.size(); ++j) {
            if(currnum == nums[j]) {
                continue;
            }
            swap(nums[i], nums[j]);
            process(nums, i + 1);
            swap(nums[i], nums[j]);
        }
    }
};