#include <iostream>
#include <vector>
using namespace std;

//查找旋转后的升序数组中的指定值
class Solution{
public:
    int search(vector<int>& nums, int target){
        int size = nums.size();
        if(size == 0) {
            return -1;
        }
        if(size == 1) {
            return nums[0] == target ? -1 : 0;
        }
        int left = 0, right = size - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] == target){
                return mid;
            }
            //[0,mid]有序
            if(nums[0] <= nums[mid]) {
                if(nums[0] <= target && target < nums[mid]){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }else{
                //[mid,right]有序
                if(nums[mid] < target && target <= nums[size - 1]) {
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    system("pause");
    return 0;
}