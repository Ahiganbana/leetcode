#include <iostream>
#include <vector>
using namespace std;

class Solution {
public :
    /*动态规划练习
    *1.定义存放历史记录的数组, 数组中记录Alice赢的情况
    *2.动态转移方程 : 
    *3.确定初值 : Alice只有拿到2的时候才会赢得比赛 故 dp[0] = 0,dp[1] = 0, dp[2] = 1
    */
    bool divisorGame(int N) {
        if(N == 0 || N == 1){
            return 0;
        }
        vector<int> dp(N + 1, 0);
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        for (int i = 3; i <= N; i++) {
            for (int j = 1; j < i; j++) {
                if(i%j == 0 && dp[i - j] == 0) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[N];
    }
};

int main() {
    Solution solution;
    int N = 0;
    cin >> N;
    int result = solution.divisorGame(N);
    cout << result << endl;
    system("pause");
    return 0;
}