#include <iostream>
#include <vector>
using namespace std;

//如果一个矩阵中有一个元素为0 则将该行该列的值都设置为0
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //1.找到矩阵中的所有0元素的位置并记录
        //2.将0元素所在的行列变为0
        int rows = matrix.size();
        if(rows == 0){
            return;
        }
        int columns = matrix[0].size();
        int row = 0, column = 0;
        bool flag = false;
        for (int i = 0; i < rows; i++) {
            if(matrix[i][0] == 0) {
                flag = true;
            }
            for (int j = 1; j < columns; j++) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < columns; j++) {
                if(matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if(matrix[0][0] == 0) {
            for (int j = 0; j < columns; j++) {
                matrix[0][j] = 0;
            }
        }
        if(flag) {
            for (int i = 0; i < rows; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};