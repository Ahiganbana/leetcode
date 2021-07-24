#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<int> company(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> company[i];
    }
    vector<int> gym(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> gym[i];
    }
    //0: 休息, 1: 锻炼, 2: 工作
    vector<vector<int>>dp (n + 1, vector<int>(3, INT_MAX));
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for(int i = 1; i <= n; ++i) {
        //健身房开门
        if(gym[i - 1] == 1) {
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
        }
        if(company[i - 1] == 1) {
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
        }
        dp[i][0] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + 1;
    }
    int result = min(dp[n][0], min(dp[n][1], dp[n][2]));
    cout << result;
    system("pause");
    return 0;
}