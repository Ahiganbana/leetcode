#include <iostream>
#include <vector>
using namespace std;

/**
 * 动态规划练习 : 求出以(row1,col1)为左上角,(row2,col2)为右下角的矩阵的值
 * 此题不同于其他的动态规划的问题,从题目中无法直接得到相应的关系.
 * 但是动态规划的主要思想在于保存历史数据方便使用.此题的主要思想正是这个.
 * 首先计算出所有以(0,0)为左上角,(i,j)为右下角的矩阵的值保存在用于存放历史数据的数组dp中.
 * 通过简单的运算得到所给部分的值
 * */

class NumMatrix {
private: 
    vector<vector<int>> dp;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int col = 0;
        if(rows != 0){
            col = matrix[0].size();
        }else if(rows == 0 || col == 0){
            return ;
        }
        //(rows+1, vector<int>(col+1, 0));
        dp.resize(rows + 1);
        for (int i = 0; i < rows + 1; i++) {
            dp[i].resize(col + 1);
        }
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < col; j++){
                dp[i + 1][j + 1] = matrix[i][j] + dp[i + 1][j] + dp[i][j + 1] - dp[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
    }
};

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> input(m, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> input[i][j];
        }
    }
    NumMatrix* obj = new NumMatrix(input);
    int result = obj->sumRegion(2, 1, 4, 3);
    cout << result << endl;
    system("pause");
    return 0;
}