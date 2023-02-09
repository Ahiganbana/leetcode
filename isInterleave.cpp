class Solution {
    //动态规划求解
    /*
    1. 确定用于存放历史信息的数组 dp[i][j]表示s1的前i个字符和s2的前j个字符能否组成s3的前i+j个字符
    2. 初始化
        如果s1 s2 s3均是空 则返回true
        如果
    3. 动态转移方程 如果s3[j + i] == s1[i] 此时看s3的前i+j-1个
        是否是s1的前i-1个和s2的前j个组成的交错字符串dp[i][j] = dp[i- 1][j];
        如果s3[i + j] == s2[j] 此时看s3的前i+j-1个是否是s2的前j-1个和s1的前i个组成的交错字符串 
        dp[i][j] = dp[i][j - 1];
    */
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size();
        int l2 = s2.size();
        int l3 = s3.size();
        vector<vector<bool>> dp(l1 + 1, vector<bool>(l2 + 1));
        dp[0][0] = 1;
        if(l1 + l2 != l3) {
            return false;
        }
        for(int i = 0; i <= l1; ++i) {
            for(int j = 0; j <= l2; ++j) {
                if(i > 0) {
                    dp[i][j] = dp[i][j] | dp[i - 1][j] && s3[i + j - 1] == s1[i - 1];
                }
                if(j > 0) {
                    dp[i][j] = dp[i][j] | dp[i][j - 1] && s3[i + j - 1] == s3[j - 1];
                }
            }
        }
        return dp[l1][l2];
    }
};