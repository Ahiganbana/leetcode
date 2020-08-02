#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) {
            return 0;
        }
        int result = -1;
        for (int i = 0; i < size; i++) {
            if(nums[i] == i) {
                result = i;
                break;
            }
        }
        return result;
    }

    int findMagicIndexII(vector<int>& nums) {
        return helper(0, nums.size() - 1, nums);
    }

    int helper(int left,int right,vector<int>& nums) {
        if(left > right) {
            return -1;
        }

        int mid = left + (right - left) / 2;
        int res = helper(left, mid - 1, nums);
        if (res != -1) {
            return res;
        }else if(nums[mid] == mid) {
            return mid;
        }else{
            return helper(nums, mid + 1, right);
        }
    }
};