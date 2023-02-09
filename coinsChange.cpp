#include <iostream>
using namespace std;

// 返回最少的硬币数
int f(vector<int> &coins, int i, int rest) {
    if(rest < 0) {
        return -1;
    }
    if(rest == 0) {
        return 0;
    }
    if(rest > 0 && i == coins.size()) {
        return -1;
    }
    int p1 = f(coins, i + 1, rest);
    int p2Next = f(coins, i + 1, rest - coins[i]);
    if(p1 == -1 && p2Next == -1) {
        return -1;
    }else {
        return p1 == -1 ? p2Next + 1 : p1;
    }
    return min(p1, p2Next + 1);
}


// 记忆化搜索
int min1(vector<int> arr, int aim) {
    vector<vector<int>> dp(arr.size() + 1, vector<int>(-2, aim + 1));
    return f(arr, aim, 0, dp);
}

// 返回最少的硬币数
int f(vector<int> &coins, int i, int rest, vector<vector<int>> &dp) {
    if(rest < 0) {
        return -1;
    }

    if(dp[index][rest] != -2) {
        return dp[index][rest];
    }
    if(rest == 0) {
        dp[i][rest] = 0;
    }
    else if(rest > 0 && i == coins.size()) {
        dp[i][rest] = -1;
    }else {
        int p1 = f(coins, i + 1, rest);
        int p2Next = f(coins, i + 1, rest - coins[i]);
        if(p1 == -1 && p2Next == -1) {
            dp[i][rest] = -1;
        }else if(p1 == -1){
            dp[i][rest] = p2Next + 1;
        }else if(p2 == -1) {
            dp[i][rest] = p1;
        }else {
            dp[i][rest] = min(p1, p2Next + 1);
        }
    }
    return dp[i][rest];
}

int min1(vector<int> arr, int aim) {
    return f(arr, aim, 0);
}

int min1(vector<int> arr, int aim) {
    vector<vector<int>> dp(arr.size() + 1, vector<int>(-2, aim + 1));
    return f(arr, aim, 0, dp);
}

// 动态规划
int f(vector<int> &coins, int i, int rest, vector<vector<int>> &dp) {
}

int min1(vector<int> arr, int aim) {
    vector<vector<int>> dp(arr.size() + 1, vector<int>(-2, aim + 1));
    for (int i = 0; i < dp.size(); ++i) {
        dp[i][0] = 0;
    }
    for (int i = 1; i < dp[0].size(); ++i) {
        dp[arr.size()][i] = -1;
    }

    for (int i = arr.size() - 1; i >= 0; --i) {
        for (int j = 1; j <= aim; ++j) {
            int p1 = dp[i][j];
            int p2Next = -1;
            if(j - arr[i] >= 0) {
                p2Next = dp[i][j - arr[i]];
            }
            if(p1 == -1 && p2Next == -1) {
                dp[i][j] = -1;
            }else {
                if(p1 == -1) {
                    dp[i][j] = p2Next + 1;
                }
                if(p2Next == -1) {
                    dp[i][j] = p1;
                }
                dp[i][j] = min(p1, p2Next + 1);
            }
        }
    }
    return dp[0][aim];
}