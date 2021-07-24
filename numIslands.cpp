#include <iostream>
#include <vector>
using namespace std;

//找到被0包围的1
class Soluiton{
    int res = 0;

public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if(rows == 0) {
            return 0;
        }
        int clounms = grid[0].size();
        if(clounms == 0) {
            return 0;
        }
        //标记每个位置的1是否被访问过
        vector<vector<bool>> visit(rows, vector<bool>(clounms, 0));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < clounms; j++) {
                if(grid[i][j] == '1' && !visit[i][j]) {
                    dfs(i, j, grid, visit);
                    res++;
                }
            }
        }
        return res;
    }

    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        visited[i][j] = 1;
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int k = 0; k < 4; k++) {
            int nextRow = i + dir[k][0];
            int nextColumn = j + dir[k][1];
            if(nextRow >= 0 && nextRow < grid.size() && nextColumn >= 0 && nextColumn < grid[i].size()) {
                if(!visited[nextRow][nextColumn] && grid[nextRow][nextColumn] == '1') {
                    dfs(nextRow, nextColumn, grid, visited);
                }
            }
        }
    }
};

int main() {
    int row = 0, cloumn = 0;
    cin >> row >> cloumn;
    Soluiton solution;
    vector<vector<char>> grid(row, vector<char>(cloumn, 0));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cloumn; j++) {
            cin >> grid[i][j];
        }
    }
    int result = solution.numIslands(grid);
    cout << result << endl;
    system("pause");
    return 0;
}

/**
4 5
1 1 1 1 0
1 1 0 1 0
1 1 0 0 0
0 0 0 0 0
*/