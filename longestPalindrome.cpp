#include <iostream>
#include <vector>
using namespace std;

class Solution{
public :
    /*动态规划练习
     * 1.确定用于保存历史数据的数组 : 二维数组 i表示s中的第i个字符 j表示s中的第j个字符
     * 2.确定转移方程 如果 bab已经是回文字符串,再向后只需要判断首位字符是否相等
     *   dp[i][j] = dp[i+1][j-1]&&s[i]==s[j];
     * 3.确定初始值 : 确定一字符回文和两字符回文 空字符串是回文 故dp[0][0] = 1;
     *   一字符是回文 故 dp[i][i] = 1;
     *   两字符串的回文 dp[i][i+1] = s[i] == s[j]
     */
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, 0));
        int maxLength = 0;
        int indexi = 0;

        if(s.size() == 0) {
            return "";
        }
        if(s.size() == 1) {
            return s;
        }

        //初始化 单字母回文 对角线为1 
        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = 1;
        }

        for (int j = 1; j < s.size(); j++) {
            for (int i = 0; i < s.size(); i++) {
                if(s[j] == s[i]) {
                    if(j - i < 3) {
                        dp[i][j] = 1;
                    }
                    else{
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                if(dp[i][j] == 1) {
                    int currLength = j - i + 1;
                    if(currLength > maxLength) {
                        maxLength = currLength;
                        indexi = i;
                    }
                }
            }
        }
            //返回使dp[i][j]为1的最大的i,j所构成的字串
            return s.substr(indexi, maxLength);
    }
};

int main() {
    Solution solution;
    string s;
    cin >> s;
    string result = solution.longestPalindrome(s);
    cout << result << endl;
    system("pause");
    return 0;
}