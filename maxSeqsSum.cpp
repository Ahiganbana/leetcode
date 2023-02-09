// 求给定数组中连续子数组的最大累加和
#include <iostream>
#include <vector>
using namespace std;

int maxSum(vector<int> &num) {
    int cur = 0;
    int maxVal = INT_MIN;
    int n = num.size();

    for (int i = 0; i < n; ++i) {
        cur += num[i];
        // maxVal 跟踪在cur加上一个数之后是否让自己变得更大,如果有更新最大值,如果没有cur不变
        maxVal = max(cur, maxVal);
        if(cur < 0) {
            cur = 0;
        }
    }
    return maxVal;
}

int main() {
    vector<int> nums = {1, 1, -1, -10, 11, 4, -6, 9, 20, -10, -2};
    int res = maxSum(nums);
    cout << res << endl;
    system("pause");
    return 0;
}