#include <iostream>
#include <vector>
using namespace std;

// 再一个给定的路上放灯 求能够监控到所有位置的最少灯数量

//贪心解法
int minLightNum(string s) {
    if(s.size() == 0) {
        return 0;
    }
    int minNum = 0;
    int i = 0;
    while(i < s.size()) {
        if(s[i] == 'X') {
            i++;
        }else {
            minNum++;
            if(i + 1 == s.size()) {
                break;
            }else {
                if(s[i + 1] == 'X') {
                    i = i + 2;
                }else {
                    i = i + 3;
                }
            }
        }
    }
    return minNum;
}

// 动态规划解法
int dpMinLightNum(string s) {
    int n = s.size();
    // dp[i]存放的是到i位置能够监控到的最少灯的数量
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
        if(s[i] == '.') {
            // 当前位置灯的数量可以从上一个位置放灯和上一个位置不放灯两种情况转移过来
        }
    }
}