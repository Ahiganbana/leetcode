#include <iostream>
#include <vector>
using namespace std;

//找出范围在1<=a[i]<=n的数组中的重复的两个数(n为数组长度)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int size = nums.size();
        vector<int> res;
        if(size == 0) {
            return res;
        }
        int index = -1, val = -1;
        for (int i = 0; i < size; ++i) {
            index = abs(nums[i] - 1);
            val = nums[index];
            if(val < 0) {
                res.push_back(nums[i]);
            }
            nums[index] = -nums[index];
        }
        return res;
    }
};
