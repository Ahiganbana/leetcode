#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public :
/**
 * 动态规划练习: 解码方法
 * 1.确定存放历史记录的数组 dp[i] 表示str[0..i]的解码方法数
 * 2.确定动态转移方程 
 *  分情况讨论 1. 如果s[i] = '0' 此时只有当s[i-1] = 1或 s[i-1] = 2的时候可以被解码
 *                  此时dp[i] = dp[i-2]
 *            2. 如果s[i] = '1' 则dp[i] = dp[i - 1] + dp[i - 2]
 *            3. 如果s[i] = '2' 且 '1'<=s[i]<='6' 则dp[i] = dp[i-1] + dp[i-2]
 * 3.确定初始值 1. 如果 s[0] = 0或s为空串 返回0 
 *             2. 如果 s[0] != 0 && s[1] == 0 dp[0] = 1 dp[1] = 1
 *             3. 如果 s[0] != 0 &&  '1'<=s[1]<='6' 则dp[0] = 1 dp[1] = 2
 */
    int numDecodings(string s) {
        int num = s.size();
        if(s[0] == '0' || num == 0) {
            return 0;
        }
        if(num == 1){
            return 1;
        }
        vector<int> dp(num, 0);
        dp[0] = 1;
        if( ((s[0] == '2')&& (s[1] >= '1' && s[1] <= '6')) || (s[0] == '1' && s[1] != '0')) {
            dp[1] = 2;
        }
        else if(s[1] == '0' && s[0] > '2') {
            dp[1] = 0;
        }
        else {
            dp[1] = 1;
        }
        for (int i = 2; i < num; i++) {
            if(s[i] == '0') {
                if(s[i-1] == '1' || s[i-1] == '2') {
                    dp[i] = dp[i - 2];
                }
                else {
                    dp[i] = 0;
                }
            }
            else if(s[i] >= '1' && s[i] <= '6') {
                if(s[i - 1] == '1' || s[i - 1] == '2') {
                    dp[i] = dp[i - 1] + dp[i - 2];
                }
                else {
                    dp[i] = dp[i - 1];
                }
            }
            else if(s[i] >= '7') {
                if(s[i - 1] == '1') {
                    dp[i] = dp[i - 1] + dp[i - 2];
                }
                else {
                    dp[i] = dp[i - 1];
                }
            }
            else{
                dp[i] = dp[i - 1];
            }
        }
        return dp[num - 1];
    }
};

int main() {
    string s;
    cin >> s;
    Solution solution;
    int result = solution.numDecodings(s);
    cout << result << endl;
    system("pause");
    return 0;
}