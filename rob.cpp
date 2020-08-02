#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /*动态规划练习
     *1.定义存放历史记录的数组.此题中数组内存放的是当前偷盗所得的最大金额
     *2.确定初始值 maxValue[0] = 0;
     *3.确定转移方程 maxValue[i] =max(maxValue[i-2],maxValue[i-1]+nums[i]); 

     *ps: 两间屋子不能连续偷
    */
    int rob(vector<int>& nums) {
        int num = nums.size();
        if(num == 0) {
            return 0;
        }
        int *maxValues = new int[num + 1];

        for (int i = 0; i < num + 1; i++) {
            maxValues[i] = 0;
        }
        maxValues[1] = nums[0];
        for (int i = 2; i <= num; i++) {
            maxValues[i] = max(maxValues[i - 1], maxValues[i - 2] + nums[i - 1]);
        }
            return maxValues[num];
    }
};
int main(){
    Solution solution;
    int n = 0;
    vector<int> nums;
    while(n != -1) {
        cin >> n;
        nums.push_back(n);
    }
    nums.pop_back();
    int result = solution.rob(nums);
    cout << result << endl;
    system("pause");
    return 0;
}