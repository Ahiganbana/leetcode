#include <iostream>
#include <vector>
using namespace std;

//只有Alice拿到2才会赢得比赛
class Solution {
public:
    bool divisorGame(int N) {
        if (N == 0 || N == 1) {
            return 0;
        }
        vector<bool> dp(N + 1, 0);
        dp[2] = 1;
        for (int i = 3; i < N; i++) {
            for (int j = 1; j < i; j++) {
                if (i % j == 0 && dp[i - 1] == 0) {
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