#include <iostream>
#include <vector>
using namespace std;

//判断数组中是否存在循环
class Solution {


public:
    bool circularArrayLoop(vector<int>& nums) {
        int size = nums.size();
        int slow, fast = 0;
        for (int i = 0; i < size; i++) {
            slow = i;
            fast = getNext(nums, i, size);
            while(nums[slow] * nums[fast] > 0 && nums[slow] * nums[getNext(nums, fast, size)] > 0){
                if(slow == fast) {
                    if(slow == getNext(nums, slow, size)){
                        break;
                    }
                    return true;
                }
                slow = getNext(nums, slow, size);
                fast = getNext(nums, getNext(nums, fast, size), size);
            }
        }
        return false;
    }

    int getNext(vector<int>& pnums, int index, int size) {
        return (pnums[index] % size + size + index) % size;
    }
};

int main() {
    cout << ((-11) % 5);
}