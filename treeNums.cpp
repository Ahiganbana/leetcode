// 给定整数n返回能够组成的二叉树的结构的种数

int process (int n) {
    if(n < 0) {
        return 0;
    }
    if(n == 0) {
        return 1;
    }
    if(n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }

    int res = 0;
    for (int leftNum = 0; leftNum <= n - 1; leftNum++) {
        int leftWays = process(leftNum);
        int rightWays = process(n - 1 - leftNum);
        res += leftWays * rightWays;
    }
    return res;
}

// 动态规划
int numTrees(int n) {
    if(n < 2) {
        return 1;
    }
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= i - 1; ++j) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
    return dp[n];
}