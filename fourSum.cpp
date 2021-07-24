#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        if(size < 4){
            return result;
        }
        //双重循环枚举a,b
        for (int first = 0; first < size - 3; ++first){
            if(first > 0 && nums[first] == nums[first - 1]){
                continue;
            }
            if(nums[first] + nums[first + 1] + nums[first + 2] + nums[first + 3] > target){
                break;
            }
            if(nums[first] + nums[size - 1] + nums[size - 2] + nums[size - 3] < target) {
                continue;
            }
            for (int second = first + 1; second < size - 2; ++second){
                if(second > first + 1 && nums[second] == nums[second - 1]){
                    continue;
                }
                if(nums[first] + nums[second] + nums[second + 1] + nums[second + 2] > target) {
                    break;
                }
                if(nums[first] + nums[second] + nums[size - 1] + nums[size - 2] < target) {
                    continue;
                }
                //双指针枚举c,d
                int third = second + 1, fourth = size - 1;
                while(third < fourth) {
                    int sum = nums[first] + nums[second] + nums[third] + nums[fourth];
                    if(sum == target) {
                        result.push_back({nums[first], nums[second], nums[third], nums[fourth]});
                        while(third < fourth && nums[third] == nums[third + 1]){
                            left++;
                        }
                        left++;
                        while(third < fourth && nums[fourth] == nums[fourth - 1]) {
                            fourth--;
                        }
                        fourth--;
                    }else if(sum < target){
                        left++;
                    }else{
                        right--;
                    }
                }
            }
        }
        return result;
    }
};