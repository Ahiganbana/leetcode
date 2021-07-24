#include <iostream>
#include <vector>
using namespace std;

//搜索又重复元素的旋转数组中的元素
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int size = nums.size();
        if(size == 0) {
            return false;
        }
        if(size == 1) {
            nums[0] == target ? true : false;
        }
        int left = 0, right = size - 1;
        while(left <= right) {
            int mid = (right + left) / 2;
            if(mid == target) {
                return true;
            }
            if(nums[0] == nums[mid]) {
                left += 1;
                continue;
            }
            //旋转后[0,mid]有序
            if(nums[0] < nums[mid]) {
                if(target >= nums[0] && target < nums[mid]) {
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }else {
                //旋转后[mid, size - 1]有序
                if(target > nums[mid] && target <= nums[size - 1]) {
                    left = mid + 1;
                }else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};