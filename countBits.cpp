#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1,0);
        for (int i = 1; i <= num; i++) {
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }
};

int main() {
    int n;
    cin >> n;
    Solution solution;
    vector<int> result = solution.countBits(n);
    for (int i = 0; i < n + 1; i++){
        cout << result[i] << " ";
    }
    system("pause");
    return 0;
}