#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
/**
 * 动态规划练习:给定数n,找到组成n的最小的平方和所需的平方的个数 (12 -> 3 (4+4+4))
 * 1.创建一个存放历史记录的数组 此处dp[i] 表示的是 
 * */
class Solution {
public:
    int numSquares(int n) {
        int size = (int)sqrt(n) + 1;
        vector<int> dp(n + 1, INT_MAX);
        vector<int> table(size, 0);
        for (int i = 1; i < size; i++){
            table[i] = i * i;
        }

        dp[0] = 0;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j < size; j++){
                if(i < table[j]){
                    break;
                }
                dp[i] = min(dp[i], dp[i - table[j]] + 1);
            }
        }
            return dp[n];
    }
};

int main() {
    Solution solution;
    int n = 0;
    cin >> n;
    int result = solution.numSquares(n);
    cout << result << endl;
    system("pause");
    return 0;
}