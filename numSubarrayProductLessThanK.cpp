#include <iostream>
#include <vector>
using namespace std;

//找出数组内乘积小于k的连续的子数组的个数
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int size = nums.size();
        int left = 0, right = 0;
        int sum = 1, count = 0;
        while (left < size ) {
            if(right < size && sum * nums[right]){
                sum = sum * nums[right];
                right++;
            }else if(left == right){
                left++;
                right++;
            }else{
                count += right - left;
                sum = sum / nums[left];
                left++;
            }
        }
        return count;
    }
};