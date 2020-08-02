#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int integerBreak(int n) {
        int maxMul = INT_MIN;
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = max(dp[i - j] * j, max(j * (i - j), dp[i]));
            }
        }
        return dp[n];
    }
};

int main() {
    int n = 0;
    cin >> n;
    Solution solution;
    int result = solution.integerBreak(n);
    cout << result << endl;
    system("pause");
    return 0;
}