#include <iostream>
#include <vector>
using namespace std;


//扫雷游戏,方法一: 深度优先搜索
class Solution {
    int dir_x[8] = {0, 1, 0, -1, 1, 1, -1, -1};
    int dir_y[8] = {1, 0, -1, 0, 1, -1, 1, -1};

public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0];
        int y = click[1];
        if(board[x][y] == 'M') {
            board[x][y] = 'X';
        }else{
            dfs(board, x, y);
        }
        return board;
    }

    void dfs(vector<vector<char>>& board, int x, int y) {
        //计算地雷的个数
        int cnt = 0;
        for(int i = 0; i < 8; ++i) {
            //遍历8个方向
            int tx = x + dir_x[i];
            int ty = y + dir_y[i];
            if(tx < 0 || tx >= board.size() || ty < 0 || ty >= board[0].size()){
                continue;
            }
            cnt += board[tx][ty] == 'M';
        }
        if(cnt > 0) {
            board[x][y] = cnt +'0';
        }else{
            board[x][y] = 'B';
            for(int i = 0; i < 8; ++i) {
                int tx = x + dir_x[i];
                int ty = y + dir_y[i];
                if(tx < 0 || tx >= board.size() || ty < 0 || ty > board.size() || board[tx][ty] != 'E'){
                    continue;
                }
                dfs(board, tx, ty);
            }
        }
    }
};

//扫雷游戏, 方法二: 广度优先搜索


int main() {
    Solution solution;
    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m, '0'));
    vector<int> click(2, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    cin >> click[0] >> click[1];

    board = solution.updateBoard(board, click);
    system("pause");
    return 0;
}

/*
4 5
E E E E E
E E M E E
E E E E E
E E E E E
3 0
*/

