#include <iostream>
#include <vector>
using namespace std;


int minCost(string str1, string str2, int ic, int dc, int rc) {
    if(str1.size() == 0 || str2.size() == 0) {
        return 0;
    }

    int row = str1.size() + 1;
    int col = str2.size() + 1;
    vector<vector<int>> dp(row, vector<int>(col, 0));

    // 初始化
    // 第一列表示从str1[0..i] 变成空串需要的代价
    for (int i = 0; i < row; ++i) {
        dp[i][0] = i * dc;
    }

    // 第一行表示从空串到str2[0..1] 需要的代价
    for (int i = 0; i < col; ++i) {
        dp[0][i] = i * ic;
    }

    for (int i = 1; i < row; ++i) {
        for (int j = 1; j < col; ++j) {
            if(str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }else {
                dp[i][j] = dp[i - 1][j - 1] + rc;
            }
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + ic);
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + dc);
        }
    }
    return dp[row - 1][col - 1];
}