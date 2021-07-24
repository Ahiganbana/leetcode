#include <iosrteam>
#include <vector>
#include <algorithm>
using namespace std;

//原地旋转一个输入的矩阵
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if(row == 0){
            return;
        }
        int colum = matrix[0].size();
        //将矩阵转置
        for (int i = 0; i < colum; ++i) {
            for (int j = i; j < row; ++j) {
                if(i == j) {
                    break;
                }
                swap(matrix[i][j], matrix[j][i]);
            }

        }
        for (int i = 0; i < row; ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};