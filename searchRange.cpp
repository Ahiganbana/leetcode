#include <iostream>
#include <vector>
using namespace std;

//在数组中找到目标值的开始位置和结束位置
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> targetRange = [ -1, -1 ];
        int firstIndex = leftIndex(nums, target, true);
        if(firstIndex == nums.size()|| nums[leftIndex] != target) {
            return targetRange;
        }
        targetRange[0] = firstIndex;
        targetRange[1] = leftIndex(nums, targetRange, false) - 1;
        return targetRange;
    }

    //找到左边第一个index
    int leftIndex(vector<int>& nums, int target, bool helper) {
        int left = 0;
        int right = nums.size();
        while(left < right) {
            int mid = (left + right) / 2;
            //在左边
            if(nums[mid] > target || (helper && target == nums[mid])) {
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
};