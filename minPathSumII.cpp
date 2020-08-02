#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        if(row == 0 || grid[0].size() == 0) {
            return 0;
        }
        int column = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(column, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = grid[0][0];
                }
                else if(i == 0 && j > 0) {
                    dp[i][j] = dp[i][j - 1] + grid[i][j];
                }
                else if(j == 0 && i > 0) {
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                }
                else{
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                }
            }
        }
        return dp[row - 1][column - 1];
    }
};

int main() {
    int n = 0;
    int m = 0;
    int num = 0;
    cin >> n >> m;
    vector<vector<int>> nums(n,vector<int>(m,0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> num;
            nums[i][j] = num;
        }
    }
    Solution solution;
    int result = solution.minPathSum(nums);
    cout << result << endl;
    system("pause");
    return 0;
}