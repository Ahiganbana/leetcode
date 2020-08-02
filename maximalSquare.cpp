#include <iostream>
#include <vector>
using namespace std;

/**
 * 动态规划练习：在一个由0,1组成的矩阵中,找到只包含1的最大正方形
 * 1.创建一个数组存放最大含1的正方形的面积 创建一个二维数组dp[i][j]表示以(i,j)为右下角的正方形的最大面积.
 * 2.确定初值 dp[0][0] = nums[0][0] dp[0][j] = nums[0][j]  dp[i][0] = nums[i][0];
 * 3.确定动态转移方程.
 *      以(i,j)为右下角顶点的正方形可能由上,左,左上三个位置扩充而来.
 *       如果nums[i][j] = 1则:
 *       dp[i][j] = min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]) + 1;
 *       否则
 *       dp[i][j] = 0
 * */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int column = matrix[0].size();
        if(rows == 0 || column == 0) {
            return 0;
        }
        vector<vector<int>> dp(rows, vector<int>(column, 0));
        dp[0][0] = matrix[0][0] - '0';
        int maxSquare = 0;
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < column; j++){
                if(i == 0 || j == 0) {
                    dp[i][j] = matrix[i][j] - '0';
                }else{
                    if(matrix[i][j] == '0'){
                        dp[i][j] = 0;
                    }else{
                        dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                    }
                }
                maxSquare = max(maxSquare, dp[i][j]);
            }
        }
        return maxSquare * maxSquare;
    }
};

int main() {
    Solution solution;
    int n, m;
    cin >> n >> m;
    vector<vector<char>> matrix(n,vector<char>(m,0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    int result = solution.maximalSquare(matrix);
    cout << result << endl;
    system("pause");
    return 0;
}