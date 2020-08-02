#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
 *动态规划练习
 *1.创建数组保存历史数据,dp数组中应该存放判断s
 *中的每一个字符是否是t的字符的结果(使用二维数组)
 *二维数组中的每一行代表s的序列前缀,列表示t的序列前缀
 *dp中的值用于指示两个子序列是否匹配
 *2.确定转移方程 : 假如dp[i-1][j-1] == 1即说明s[i-1]和t[j]匹配
 *成功 此时 dp[i-1][j] = 1; 如果dp[i-1][j-1] == 0说明s[i-1]不是
 *t[j]的子序列
 *3.初始化: i == 0;j == 0时,s,t均为空串,此时匹配成功,故dp[0][0] = 1;
 *         i == 0; j > 0时,s为空串,t非空,此时同样匹配成功,故dp[0][j] = 1;
 *         i > 0; j == 0时,s非空,t为空串,此时匹配不成功,故dp[i][0] = 0;
 */
class Solution {
public :
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(2, vector<int>(t.size() + 1, 0));
        for (int i = 0; i <= s.size(); ++i) {
            for (int j = 0; j <= t.size(); ++j) {
                if(i == 0 && j == 0) {
                    dp[i%2][j] = 1;
                }
                else if(i == 0 && j > 0) {
                    dp[i%2][j] = 1;
                }
                else if(i > 0 && j == 0) {
                    dp[i%2][j] = 0;
                }
                else {
                    if(s[i - 1] == t[j - 1]) {
                        dp[i%2][j] = dp[(i - 1)%2][j - 1];
                    }
                    else {
                        dp[i%2][j] = dp[i%2][j - 1];
                    }
                }
            }
        }
        return dp[s.size()%2][t.size()];
    }
};
int main() {
    Solution solution;
    string s, t;
    cin >> s >> t;
    int result = solution.isSubsequence(s, t);
    cout << result << endl;
    system("pause");
    return 0;
}