//输出杨辉三角的第k行第j列
#include<iostream>
#include<vector>
using namespace std;

// 动态规划求解
/**1. 定义用于存放历史数据的数组
 * dp[i][j]存放的是第i行第j列的值
 * */
int getValue(int rowIndex, int columnIndex) {
    vector<vector<int>> dp(rowIndex + 1, vector<int>(rowIndex + 1, 0));
    
    // 初始化
    for (int i = 0; i <= rowIndex; ++i) {
        for (int j = 0; j <= rowIndex; ++j) {
            if(j == 0) {
                dp[i][j] = 1;
            }
            if(i == j) {
                dp[i][j] = 1;
            }
        }
    }

    // 动态转移方程
    for (int i = 1; i <= rowIndex; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    return dp[rowIndex - 1][columnIndex - 1];
}

int main() {
    int rowIndex = 0, columnIndex = 0;
    cin >> rowIndex >> columnIndex;
    int result = getValue(rowIndex, columnIndex);
    cout << result << endl;
    system("pause");
    return 0;
}

