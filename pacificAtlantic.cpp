#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> res;
    //标记是否访问过
    vector<vector<int>> visited;
    //表明水流的源头
    vector<vector<int>> ao;
    vector<vector<int>> po;

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if(rows == 0) {
            return res;
        }
        int columns = matrix[0].size();
        visited.resize(rows);
        ao.resize(rows);
        po.resize(rows);
        for (int i = 0; i < rows; ++i) {
            visited[i].resize(columns);
            ao[i].resize(columns);
            po[i].resize(columns);
        }
        for (int j = 0; j < columns; ++j) {
            dfs(0, j, matrix, true);
        }
        clearHistory(visited, rows, columns);
        for (int i = 0; i < rows; ++i) {
            dfs(i, 0, matrix, true);
        }
        clearHistory(visited, rows, columns);
        for (int i = 0; i < rows; ++i) {
            dfs(i, columns - 1, matrix, false);
        }
        clearHistory(visited, rows, columns);
        for (int j = 0; j < columns; ++j) {
            dfs(rows - 1, j, matrix, false);
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (ao[i][j] == 1 && po[i][j] == 1) {
                        vector<int> tmp = {i, j};
                        res.emplace_back(i, j);
                    }
                }
            }
            return res;
    }

    void clearHistory(vector<vector<int>>& vec, int rows, int columns) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                vec[i][j] = 0;
            }
        }
    }

    void dfs(int i, int j, vector<vector<int>>& matrix, bool flag) {
        if(visited[i][j] == 1) {
            return;
        }
        visited[i][j] = 1;
        if(flag){
            po[i][j] = 1;
        }else{
            ao[i][j] = 1;
        }
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int k = 0; k < 4; ++k) {
            int nextRow = i + dir[k][0];
            int nextColmun = j + dir[k][1];
            if(nextRow >= 0 && nextRow < matrix.size() && nextColmun >= 0 && nextColmun < matrix[i].size()) {
                if(matrix[i][j] <= matrix[nextRow][nextColmun]) {
                    //水流可以流动
                    //水流流进了大西洋和太平洋
                    dfs(nextRow, nextColmun, matrix, flag);
                }else{
                    continue;
                }
            }
        }
        return;
    }
};

int main() {
    vector<vector<int>> vec;
    int rows = 0, columns = 0;
    Solution solution;
    cin >> rows >> columns;
    vec.resize(rows);
    for (int i = 0; i < rows; i++) {
        vec[i].resize(columns);
        for (int j = 0; j < columns; j++) {
            cin >> vec[i][j];
        }
    }
    vector<vector<int>> res = solution.pacificAtlantic(vec);
}

/*
5 5
1 2 2 3 5
3 2 3 4 4
2 4 5 3 1
6 7 1 4 5
5 1 1 2 4
*/