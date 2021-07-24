#include <iostream>
#include <vector>
using namespace std;

//找到数组中的峰值元素(使用O(logN的时间复杂度))
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) {
            return 0;
        }
        int maxIndex = getMaxIndex(nums, 0, size - 1, 0);
        return maxIndex;
    }

    int getMaxIndex(vector<int>& nums, int left, int right, int max) {
        if(right - left <= 1) {
            if(nums[left] >= nums[right]) {
                max = left;
            }else{
                max = right;
            }
        }else{
            int max1 = INT_MIN;
            int max2 = INT_MIN;
            int mid = left + (left + right) / 2;
            max1 = getMaxIndex(nums, left, mid, max1);
            max2 = getMaxIndex(nums, mid + 1, right, max2);
            if(nums[max1] > nums[max2]) {
                max = max1;
            }else{
                max = max2;
            }
        }
        return max;
    }
};