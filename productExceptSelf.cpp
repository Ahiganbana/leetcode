#include <iostream>
#include <vector>
using namespace std;

//返回一个表示数组除了当前位置之外其余元素的乘积的数组
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size);
        vector<int> left(size, 0), right(size, 0);
        left[0] = 1, right[size - 1] = 1;
        for (int i = 1; i < size; ++i) {
            left[i] = left[i - 1] * nums[i - 1];
        }
        for (int i = size - 2; i >= 0; --i) {
            right[i] = right[i + 1] * nums[i + 1];
        }
        for (int i = 0; i < size; ++i) {
            result[i] = left[i] * right[i];
        }
        return result;
    }
};