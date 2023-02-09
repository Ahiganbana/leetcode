// 模拟机器人走路模型
// 从start 走到 end 必须走k 步, 求所有的走法
// 机器人可以左右移动
#include <vector>
#include <iostream>
using namespace std;

// n 表示一共是1~n的位置
// end 表示最终目标
// rest 表示还剩多少步需要走
// cur 表示当前来到的位置
// 返回到达cur后,有多少种方法数
int f(int n, int end, int rest, int cur) {
    if(rest == 0) {
        return cur == end ? 1 : 0;
    }
    if(cur == 1) {
        return f(n, end, rest - 1, cur + 1);
    }
    if(cur == N) {
        return f(n, end, rest - 1, cur - 1);
    }
    return f(n, end, rest - 1, cur - 1) + f(n, end, rest - 1, cur + 1);
}

int walkWays(int n, int end, int start, int k) {
    return f(n, end, k, start);
}

// 记忆化搜索版本
int f2(int n, int end, int rest, int cur, vector<vector<int>> &dp) {
    if(dp[rest][cur] != -1) {
        return dp[rest][cur];
    }
    if(rest == 0) {
        dp[rest][cur] = cur == end ? 1 : 0;
    }
    else if(cur == 1) {
        dp[rest][cur] = f2(n, end, rest - 1, cur + 1);
    }
    else if(cur == N) {
        dp[rest][cur] = f2(n, end, rest - 1, cur - 1);
    }else {
        dp[rest][cur] = f2(n, end, rest - 1, cur - 1) + f2(n, end, rest - 1, cur + 1);
    }
    
    return dp[rest][cur];
}

int walkWays1(int n, int end, int start, int k) {
    // 递归解法改记忆化搜索 -> 只需要记录下可变参数的部分.
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
    return f2(n, end, k, start, dp);
}

// 动态规划
int f3(int n, int end, int rest, int cur, vector<vector<int>> &dp) {
    int n = dp.size();
    int m = dp[0].size();
    // 初始化
    for (int i = 0; i < m; ++i) {
        if(i == end) {
            dp[0][i] = 1;
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if(j == 1) {
                dp[i][j] = dp[i - 1][j + 1];
            }
            else if(j == m - 1) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
            }
        }
    }
    return dp[rest][end];
}

int walkWays2(int n, int end, int start, int k) {
    // 记忆化搜索改动态规划 -> 需要记录下前后的依赖关系.
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
    return f3(n, end, k, start, dp);
}