#include <iostream>
#include <vector>
using namespace std;

//生命游戏:使用4条规则更新矩阵中的元素
/**
 * 0 代表死细胞, 1 代表活细胞
 * 规则:
 * 1. 当前是活细胞,且周围八个位置上的活细胞数少于两个,活细胞死亡
 * 2. 当前是活细胞,且周围八个位置有2-3个活细胞,活细胞继续存活
 * 3. 当前是活细胞,且周围八个位置超过3个活细胞,活细胞死亡
 * 4. 当前是死细胞,且周围八个位置正好有3个活细胞,死细胞复活.
 * */
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<int> direction = {0, 1, -1};
        int rows = board.size();
        if(rows == 0) {
            return;
        }
        int columns = board[0].size();
        vector<vector<int>> copyOfBoard(rows, vector<int>(columns, 0));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                copyOfBoard[i][j] = board[i][j];
            }
        }
        //判断
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                int liveNeibor = 0;
                for (int row = 0; row < 3; row++) {
                    for (int col = 0; col < 3; col++) {
                        if(!(direction[i] == 0 && direction[j] == 0)) {
                            int r = row + direction[i];
                            int c = col + direction[j];
                        }
                        if((r < rows && r >= 0) && (c < cols && c >=0) && (copyOfBoard[r][c] == 1)) {
                            liveNeibor++;
                        }
                    }
                }
                if((copyOfBoard[i][j] == 1) && ((liveNeibor < 2) || (liveNeibor > 3))) {
                    board[i][j] = 0;
                }
                if(copyOfBoard[i][j] == 0 && (liveNeibor == 3)) {
                    board[i][j] = 1;
                }
            }
        }
    }
};