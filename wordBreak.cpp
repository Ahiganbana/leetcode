#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * 动态规划训练: 单词拆分,判断给定的字符串能否分割出多个单词
 * 1. 确定动态规划的数组
 *      数组内存放是否能组成单词的结果
 * 2. 确定初始值
 *      当只有一个字母的时候为true
 * 3. 动态转移方程
 *      设置两个指针i,j,i表示当前字符串s的子字符串s'的长度,j表示s'拆分的位置.将s'拆分为(0,j)和(j+1,i)
 *      dp[i] = dp[j] & wordDict.contains(s.substring(j+1,i))
 * */

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.length();
        if(size == 0) {
            return true;
        }
        bool dp[size + 1];
        dp[0] = true;

        vector<string>::iterator iter;
        string sub;
        for (int i = 1; i <= size; i++) {
            for (int j = 0; j < i; j++) {
                sub = s.substr(j, i-j);
                iter = std :: find(wordDict.begin(), wordDict.end(), sub);
                if(dp[j] && !(iter == wordDict.end())){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[size];
    }
};

int main() {
    Solution solution;
    string input;
    cin >> input;
    int n = 0;
    cin >> n;

    vector<string> wordDict(n);
    for (int i = 0; i < n; i++) {
        cin >> wordDict[i];
    }
    bool result = solution.wordBreak(input, wordDict);
    cout << result << endl;
    system("pause");
}