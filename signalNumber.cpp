// 找到数组中只出现一次的数字除了此数字外  其余数字都出现3次
#include <iostream>
#include <vector>
using namespace std;
/**
 * 1. 遍历数组中每个数的每一位如果该位置是1计数器++;
 * 2. 如果计数器的结果%3 的余数是0.说明是出现了3次的数 如果不是 说明出现1次的数的该位置是1
 * */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int mask = 1; mask != 0; mask <<= 1) {
            int cnt = 0;                     
            for(int num : nums) {
                if((num & mask) != 0) {
                    cnt++;
                }
            }
            if(cnt % 3 == 1) {
                res |= mask;
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums = {-2, -2, 1, 1, 4, 1, 4, 4, -4, -2};
    int res = Solution().singleNumber(nums);
    cout << res << endl;
    system("pause");
    return 0;
}