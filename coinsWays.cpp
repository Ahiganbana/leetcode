// 数组中存放的是硬币的面额
// 返回能够找零的方法数

#include <iostream>
#include <vector>
using namespace std;

int way1(vector<int> &arr, int aim) {
    return process(arr, 0, aim);
}

int process(vector<int> &arr, int index, int rest) {
    if(index == arr.size()) {
        return rest == 0 ? 1 : 0;
    }
    int ways = 0;
    for (int zhang = 0; arr[index] * zhang <= rest; ++zhang) {
        ways += process(arr, index + 1, rest - arr[index] * zhang);
    }
    return ways;
}

// 动态规划版本
int way2(vector<int> &arr, int aim) {
    return process2(arr, 0, aim);
}

int process2(vector<int> &arr, int index, int aim) {
    int n = arr.size();
    vector < vector<int> dp(n + 1, vector<int>(aim + 1, 0));
    dp[N][0] = 1;
    for (int i = N - 1; i >= 0; --i) {
        for (int j = 0; j <= aim; ++j) {
            // int ways = 0;
            // for (int zhang = 0; arr[i] * zhang <= aim; ++zhang) {
            //     ways += dp[i + 1][aim - arr[i] * zhang];
            // }
            // dp[i][j] = ways;
            // 斜率优化 (有枚举行为可以进行代替)
            dp[i][j] = dp[i + 1][j];
            if(aim - arr[i] >= 0) {
                dp[i][j] += dp[i][aim - arr[i]];
            }
        }
    }
    return dp[0][aim];
}