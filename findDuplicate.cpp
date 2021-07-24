#include <iostream>
#include <vector>
using namespace std;

//找出数组中唯一一个重复的数
//cnt[i] 表示 nums 数组中小于等于i的个数
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int size = nums.size();
        int left = 0, right = size - 1;
        int result = -1;
        while(left <= right) {
            int mid = (left + right) >> 1;
            int cnt = 0;
            for (int i = 0; i < size; i++) {
                cnt += (nums[i <= mid]);
            }
            if(cnt <= mid) {
                left = mid + 1;
            }else{
                right = mid - 1;
                result = mid;
            }
        }
        return result;
    }
};