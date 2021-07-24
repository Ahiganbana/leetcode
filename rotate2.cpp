#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//原地将数组向右移动k个位置
class Solution {
public:
    void rotate1(vector<int>& nums, int k) {
        int size = nums.size();
        if(size == 0) {
            return;
        }
        if(k >= size) {
            k = k % size;
        }
        int tmp = 0;
        for (int i = 0; i < k; i ++) {
            nums.erase(nums.end() - i - 1);
            nums.insert(nums.begin(), tmp);
        }
    }

    //将数组旋转k位相当于先将整个数组翻转
    //再将前k个翻转
    //再将后n-k个翻转
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if(k >= size) {
            k = k % size;
        }
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k + 1, nums.end());
    }
};