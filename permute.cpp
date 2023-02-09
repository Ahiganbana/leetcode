#include <vector>
#include <iostream>
using namespace std;

class Solution {
    vector<vector<int>> res;
    vector<int> path;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        process(nums, 0);
        return res;
    }

    void process(vector<int> &nums, int i) {
        if(i == nums.size()) {
            res.push_back(nums);
        }

        for(int j = i + 1; j < nums.size(); ++j) {
            swap(nums[i], nums[j]);
            process(nums, j);
            swap(nums[i], nums[j]);
        }
    }
};