#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int size = matrix.size();
        int columns = matrix[0].size();
        vector<vector<int>> res(size, vector<int>(columns));
        vector<vector<int>> seen(size, vecotr<int>(columns));
        queue<pair<int, int>> q;
        //将所有的0添加进队列中
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < columns; ++j) {
                if(matrix[i][j] == 0) {
                    q.emplace(i, j);
                    seen[i][j] = 1;
                }
            }
        }

        //广度优先搜索
        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int tx = i + dir[k][0];
                int ty = j + dir[k][1];
                if(tx >= 0 && tx < matrix.size() && ty >= 0 && ty < matrix[0].size() && !seen[tx][ty]) {
                    //如果matrix旁边不是0
                    res[tx][ty] = res[i][j] + 1;
                    q.emplace(tx, ty);
                    seen[tx][ty] = 1;
                }
            }
        }
        return res;
    }

    //深度优先搜索
/*     void dfs(vactor<vactor<int>>& matrix, int x, int y) {
        int cnt = 0;
        if(matrix[x][y] == 0) {
            return;
        }else{
            for (int i = 0; i < 4; ++i) {
                int tx = x + dir[i][0];
                int ty = y + dir[i][1];
                if(tx < 0 || tx >= matrix.size() || ty < 0 || ty >= matrix[0].size()) {
                    continue;
                }
                if(matrix[tx][ty] == 0) {
                    cnt += 1;
                }
            }
        }
    } */
};