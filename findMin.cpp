#include <iostream>
#include <vector>
using namespace std;

//找到旋转数组中的最小值
class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) {
            return nums[0];
        }
        int left = 0, right = size - 1;
        int result = 0;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] > nums[mid + 1]) {
                result =  nums[mid + 1];
                break;
            }
            if(nums[mid - 1] > nums[mid]) {
                result = nums[mid];
                break;
            }
            if(nums[mid] > nums[right]){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
    }
};

