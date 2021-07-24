#include <iostream>
#include <vector>
using namespace std;

//找到所有被包围的'X'并将区域里所有的'O'用'X'填充
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if(row == 0) {
            return;
        }
        int column = board[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if(i == 0 || i == row - 1 || j == 0 || j == column - 1) {
                    dfs(i, j, board);
                }
            }
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if(board[i][j] == 'A') {
                    board[i][j] = 'O';
                }else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(int i, int j, vector<vector<char>>& board){
        if(i < 0 || i > board.size() - 1 || j < 0 || j > board[i].size() - 1){
            return;
        }
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        if (board[i][j] == 'O') {
            board[i][j] = 'A';
            for (int k = 0; k < 4; ++k) {
                dfs(i + dir[k][0], j + dir[k][1], board);
            }
        }
    }
};