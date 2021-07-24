#include <iostream>
#include <vector>
using namespace std;

//在具有如下性指的矩阵中寻找target值
    //-每一行均为升序
    //-下一行第一个数大于上一行最后一个数
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if(rows == 0) {
            return false;
        }
        int columns = matrix[0].size();
        int row = 0;
        if(target < matrix[0][0]) {
            return false;
        }
        for (int i = 0; i < rows; i++) {
            if(target < matrix[i][0] || target > matrix[i][columns - 1]) {
                break;
            }else if(target >= matrix[i][0] && target <= matrix[i][columns - 1]) {
                row = i;
            }
        }
        int left = 0, right = columns - 1;
        while(left < right) {
            int mid = (left + right) / 2;
            if(matrix[row][mid] == target) {
                return true;
            }
            if(matrix[row][mid] < target) {
                left = mid + 1;
            }else if(matrix[row][mid] > target) {
                right = mis - 1;
            }
        }
        return false;
    }
};