#include <iostream>
#include <vector>
using namespace std;

int countIsland(vector<vector<int>> &m) {
    if(m.size() == 0 || m[0],size() == 0) {
        return 0;
    }
    int N = m.size();
    int M = m[0].size();
    int res = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if(m[i][j] == 1) {
                res++;
                infect(m, i, j, N, M);
            }
        }
    }
    return res;
}

void infect(vector<vector<int>> &m, int i, int j, int N, int M) {
    if(i < 0 || i >= N || j < 0 || j >= M || m[i][j] != 1) {
        return;
    }
    m[i][j] = 2;
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // 四个方向
    for (int k = 0; k < 4; ++k) {
        int nextRow = i + dir[k][0];
        int nextColumn = j + dir[k][1];
        infect(m, nextRow, nextColumn, N, M);
    }
}
