#include <iostream>
#include <vector>
using namespace std;

//一趟排序
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        int p0 = 0, p1 = 0;
        for (int i = 0; i < size; i++) {
            if(nums[i] == 1){
                swap(nums[i], nums[p1]);
                p1++;
            }
            if(nums[i] == 0) {
                swap(nums[i], nums[p0]);
                if(nums[i] == 1) {
                    swap(nums[i], nums[p1]);
                }
                p1++;
                p0++;
            }
        }
    }
};