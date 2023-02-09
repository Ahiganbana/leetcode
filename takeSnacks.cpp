#include <iostream>
#include <vector>
using namespace std;

// v 表示背包的体积 , weight表示第i袋零食的体积是weight[i]
int takeSnakeWays(vector<int> &weight, int v) {
    if(weight.size() == 0) {
        return 1;
    }
    vector<vector<int>> dp(weight.size() + 1, vector<int>(v + 1, 0));
    dp[0][0] = 1;
    int ans = 0;
    for (int i = 0; i < weight.size(); ++i) {
        dp[i][0] = 1;
    }
    for (int i = 0; i < weight[0].size(); ++i) {
        dp[0][i] = 1;
    }
    for (int i = 1; i < weight.size(); ++i) {
        for (int j = 1; j <= v; ++j){
            if (j - weight[i] >= 0) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - weight[i]];
            }
        }
    }
    for (int i = 0; i <=v ; ++i) {
        ans += dp[weight[0].size() - 1][i];
    }
    return 0;
}