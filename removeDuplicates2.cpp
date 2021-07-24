#include <iostream>
#include <vector>
using namespace std;

//移除数组中的重复元素,每个元素至多出现两次
//返回移除多余元素后的数组长度
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size < 2) {
            return size;
        }
        int i = 0, j = 1;
        for (int k = 2; k < size - 1; ++j) {
            if(nums[i] != nums[k]) {
                i++;
                j++;
                nums[j] = nums[k];
            }
        }
        return j + 1;
    }
};