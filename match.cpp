#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str string字符串 
     * @param pattern string字符串 
     * @return bool布尔型
     */
    bool match(string str, string pattern) {
        // write code here
        int n = str.size();
        int p = pattern.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(p + 1, 0));
        for(int i = 0; i <= n; ++i) {
            for(int j = 0; j <= p; ++j){
                if(j == 0){
                    //模式串为空, 且字符串不为空,匹配失败
                    dp[i][j] = (i== 0);
                }else{
                    if(pattern[j - 1] != '*'){
                        if(i > 0 && (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '.')){
                            dp[i][j] = dp[i - 1][j - 1];
                        }
                    }else{
                        //出现0次
                        if(j >= 2) {
                            dp[i][j] = dp[i][j - 2];
                        }
                        //出现多次
                        if(i > 0 && j >= 2 && (str[i - 1] == pattern[j - 2] || pattern[j - 2] == '.')){
                            dp[i][j] = dp[i - 1][j];
                        }
                    }
                }
            }
        }
        return dp[n][p];
    }
};

int main() {
    string str = "", pattern = "";
    cin >> str >> pattern;
    Solution solution;
    bool result = solution.match(str, pattern);
    cout << result << endl;
    return 0;
}