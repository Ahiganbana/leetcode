#include <iostream>
#include <vector>
using namespace std;

// 返回马走步到达a,b的方法数
// 从i,j位置出发往a,b
int process(vector<vector<int>> &arr, int i, int j, int k) {
    if(i < 0 || i > 8 || y < 0 || y > 9) {
        return 0;
    }
    if(k == 0) {
        return (i == 0 && j == 0) ? 1 : 0;
    }
    return process(arr, i + 2, j - 1, k - 1) + process(arr, i + 2, j + 1, k - 1) +
           process(arr, i + 1, j - 2, k - 1) + process(arr, i + 1, j + 1, k - 1) +
           process(arr, i - 1, j - 2, k - 1) + process(arr, i - 1, j + 2, k - 1) +
           process(arr, i - 2, j - 1, k - 1) + process(arr, i - 2, j + 1, k - 1);
}

// 动态规划
int dpways(vector<vector<int>> &arr, int i, int j, int a, int b, int k) {
    if(i < 0 || i > 8 || y < 0 || y > 9 || k < 0) {
        return 0;
    }

    vector<vector<vector<int>>> dp(arr.size(), vector<vector<int>>(arr[0].size(), vector<int>(k, 0)));
    dp[0][0][0] = 1;

    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < 9; ++j) {
            for (int c = 0; c < 10; c++) {
                dp[j][c][i] += dp[j - 1][c + 2][h - 1];
                dp[j][c][i] += dp[j + 1][c + 2][h - 1];
                dp[j][c][i] += dp[j + 2][c + 1][h - 1];
                dp[j][c][i] += dp[j + 1][c - 1][h - 1];
                dp[j][c][i] += dp[j + 1][c - 2][h - 1];
                dp[j][c][i] += dp[j - 1][c - 2][h - 1];
                dp[j][c][i] += dp[j - 2][c - 1][h - 1];
                dp[j][c][i] += dp[j - 2][c + 1][h - 1];
            }
        }
    }
}