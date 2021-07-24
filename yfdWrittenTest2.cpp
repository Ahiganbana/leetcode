#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 交错字符串的变种 增加 n< K 的条件
/**
 * 交错字符串的动态规划: 
 * 动态规划可以用于求解s3是否是由s1 s2组成的交错字符串
 * 1. 确定用于存放历史信息的数组 dp[i][j]表示s1的前i个字符和s2的前j个字符能否组成s3的前i+j个字符
 * 2. 初始化 dp[0][0] = 1 表示s1 s2 s3 均为空
 * 3. 动态转移方程 
 *      如果s3[i+j] == s1[i] 看s3的前i+j-1个是否是s1的前i-1个和s2的前j个组成 dp[i][j] = dp[i-1][j]
 *      如果s3[i+j] == s2[j] 看s3的前i+j-1个是否是s2的前j-1个和s1的前i个组成 dp[i][j] = dp[i][j-1]
 * 
 * */
bool resolve(string s1, string s2, string s3) {
    int l1 = s1.size();
    int l2 = s2.size();
    int l3 = s3.size();
    if(l1 + l2 != l3) {
        return 0;
    }
    vector<vector<bool>> dp(l1 + 1, vector<bool>(l2 + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i <= l1; ++i) {
        for (int j = 0; j <= l2; ++j) {
            // 判断是否是交错字符串
            if(i > 0) {
                dp[i][j] = dp[i][j] | (dp[i - 1][j] && s3[i + j - 1] == s1[i - 1]);
            }
            if(j > 0) {
                dp[i][j] = dp[i][j] | (dp[i][j - 1] && s3[i + j - 1] == s2[j - 1]);
            }
        }
    }
    return dp[l1][l2];
}

// 计算交错的次数
int calculate(string s1, string s2, string s3) {
    int ptr1 = 0, ptr2 = 0, cnt = 1;
    for (int i = 0; i < s3.size(); ++i) {
        if(s3[i] == s1[ptr1]) {
            if(ptr1 < s1.size()) {
                ++ptr1;
            }
        }else {
            if(s3[i] == s2[ptr2] && ptr2 < s2.size()) {
                ++ptr2;
            }
        }
    }
    return cnt;
}

int main() {
    int T = 0, cnt = 0;
    string s1, s2, s3;
    int K = 0;
    cin >> T;
    while(cnt < T) {
        cin >> s1 >> s2 >> s3 >> K;
        cnt++;
        if(resolve(s1, s2, s3)) {
            int res = calculate(s1, s2, s3);
            if(res <= K) {
                cout << 1 << endl;
            }else {
                cout << 0 << endl;
            }
        }else {
            cout << 0 << endl;
        }
    }
    system("pause");
    return 0;
}
