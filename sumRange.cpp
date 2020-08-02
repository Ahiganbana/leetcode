#include <iostream>
#include <vector>
using namespace std;

/*
*动态规划练习
* 求数组i到j之间的数之和
* 1.定义用于存放历史记录的数组dp,
* 数组中存放的是0到i之间的和;
* 2.确定转移方程dp[i+1] = dp[i] + nums[i];
* 3.确定初值
*/

class NumArray {
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        dp.resize(nums.size());
    }

    void sumOfArray(int i) {
        for(int index = 1; index <= i; index++) {
            dp[index] = dp[index - 1] + nums[index];
        }
    }
    int sumRange(int i, int j) {
        if(this->nums.size() != 0) {
            this->dp[0] = nums[0];
            sumOfArray(j);
        if(i == 0) {
            return dp[j];
        }
        return dp[j] - dp[i] + this->nums[i];
        }
        return 0;
    }

private:
    vector<int> nums;
    vector<int> dp;
};


int main() {
    int n = 0;
    vector<int> nums;
    while(n != -100) {
        cin >> n;
        nums.push_back(n);
    }
    nums.pop_back();
    int i = 0;
    int j = 0;
    int result = 0;
    NumArray *numarray = new NumArray(nums);
    while(i != -100 && j != -100) {
        cin >> i >> j;
        result = numarray->sumRange(i, j);
        cout << result << endl;
    }
    system("pause");
    return 0;
}