#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size; ++i) {
            //枚举a,每次枚举的a都不相同
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            //枚举c
            int k = size - 1;
            int target = -nums[i];
            //枚举b
            for (int j = i + 1; j < size; ++j){
                if(j > i + 1 && nums[j] == nums[j - 1]){
                    continue;
                }
                //b的约束条件: b的指针小于c的指针,并且b,c和大于target
                while(j < k && nums[j] + nums[k] > target) {
                    --k;
                }
                if(j == k){
                    break;
                }
                if(nums[j] + nums[k] == target){
                    result.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }
        return result;
    }
};