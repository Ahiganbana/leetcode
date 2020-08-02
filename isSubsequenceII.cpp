#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int> dp(2, vector<int>(t.size() + 1, 0));
        for (int i = 0; i <= s.size(); ++i) {
            for (int j = 0; j <= t.size(); ++j) {
                if(i == 0 && j == 0){
                    dp[i%2][j] = 1;
                }else if(i == 0 && j > 0) {
                    dp[i%2][j] = 1;
                }else if(i > 0 && j == 0) {
                    dp[i%2][j] = 0;
                }else {
                    if (s[i - 1] == t[j - 1]) {
                        dp[i % 2][j] = dp[(i - 1) % 2][j - 1];
                    }else {
                        dp[i % 2][j] = dp[i % 2][j - 1];
                    }
                }
            }
        }
        return dp[s.size() % 2][t.size()];
    }
};