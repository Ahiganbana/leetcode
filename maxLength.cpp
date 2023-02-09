// 求一个只包含括号的字符串内 最大匹配字串的长度
#include <iostream>
#include <vector>
using namespace std;

int maxLength(string s) {
    if(s.size() == 0) {
        return 0;
    }
    // dp[i]中存放的是 以i结尾的字符串的最长字串的长度
    vector<int> dp(s.size(), 0);
    int pre = 0;
    int maxl = 0;
    for (int i = 1; i < s.size(); ++i) {
        if(s[i] == ')') {
            pre = i - dp[i - 1] - 1;
            if(pre >= 0 && s[pre] == '(') {
                dp[i] = dp[i - 1] + 2 + (pre > 0 ? dp[pre - 1] : 0);
            }
        }
        maxl = max(maxl, dp[i]);
    }
    return maxl;
}