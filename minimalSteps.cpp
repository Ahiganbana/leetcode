#include <iostream>
#include <vector>
#include <queue>
#include <pair>
using namespace std;

class Solution {
public:
    //x方向上的上下左右
    int dx[4] = {1, -1, 0, 0};
    //y方向上的山下左右
    int dy[4] = {0, 0, 1, -1};
    //组成迷宫矩阵的长宽
    int n, m;

    bool inBound(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    vector<vector<int>> bfs(int x, int y, vector<string> &maze){
        //计算出每两个特殊机关之间的最小距离
        vector<vector<int>> ret(n, vector<int>(m, -1));
        ret[x][y] = 0;
        queue<pair<int, int>> qu;
        qu.push({x, y});
        while(!qu.empty()) {
            auto q = qu.front();
            qu.pop();
            int x = q.first, y = q.second;
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if(inBound(nx,ny) && maze[nx][ny] != '#' && ret[nx][ny] == -1) {
                    ret[nx][ny] = ret[x][y] + 1;
                    qu.push({nx, ny});
                } 
            }
        }
        return ret;
    }

    int minimalSteps(vector<string>& maze) {
        n = maze.size();
        m = maze[0].size();
        vector<pair<int, int>> buttons, stones;
        int sx, sy, tx, ty;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(maze[i][j] == 'M') {
                    buttons.push_back({i, j});
                }
                if(maze[i][j] == 'O') {
                    stones.push_back({i, j});
                }
                if(maze[i][j] == 'S') {
                    sx = i, sy = j;
                }
                if(maze[i][j] == 'T') {
                    tx = i, ty = j;
                }
             }
        }
        int nb = buttons.size();
        int ns = stones.size();
        vector<vector<int>> start_dist = bfs(sx, sy, maze);

        //边界情况
        if (nb == 0) {
            return start_dist[tx][ty];
        }
        //从某个机关到其他机关/起点/重点的最短距离
        vector<vector<int>> dist(nb, vector<int>(nb + 2, -1));
        //中间结果
        vector<vector<vector<int>>> dd(nb);
        for (int i = 0; i < nb; i++) {
            vector<vector<int>> d = bfs(buttons[i].first, buttons[i].second, maze);
            dd[i] = d;
            //从某个点到终点不需要石头
            dist[i][nb + 1] = d[tx][ty];
        }

        for (int i = 0; i < nb; i++) {
            int tmp = -1;
            for (int k = 0; k < ns; k++) {
                int mid_x = stones[k].first, mid_y = stones[k].second;
                if(dd[i][mid_x][mid_y] != -1 && start_dist[mid_x][mid_y] != -1) {
                    if(tmp == -1 || tmp > dd[i][mid_x][mid_y] + start_dist[mid_x][mid_y]) {
                        tmp = dd[i][mid_x][mid_y] + start_dist[mid_x][mid_y];
                    }
                }
            }
            dist[i][nb] = tmp;
            for (int j = i + 1; j < nb; j++) {
                int mn = -1;
                for (int k = 0; k < ns; k++) {
                    int mid_x = stones[k].first, mid_y = stones[k].second;
                    if(dd[i][mid_x][mid_y] != -1 && dd[j][mid_x][mid_y] != -1) {
                         if(mn == -1 || mn > dd[i][mid_x][mid_y] + dd[j][mid_x][mid_y]){
                        mn = dd[i][mid_x][mid_y] + dd[j][mid_x][mid_y];
                        }
                    }
                }
                dist[i][j] = mn;
                dist[j][i] = mn;
            }
        }

        //无法达成的情形
        for (int i = 0; i < nb; i++) {
            if (dist[i][nb] == -1 || dist[i][nb + 1] == -1){
                return -1;
            }
        }

        //dp数组,-1 表示没有找到
        vector<vector<int>> dp(1 << nb, vector<int>(nb, -1));
        for (int i = 0; i < nb; i++) {
            dp[1 << i][i] = dist[i][nb];
        }

        for (int mask = 1; mask < (1 << nb); mask++) {
            for (int i = 0; i < nb; i++) {
                if (mask & (1 << i)) {
                    for (int j = 0; j < nb; j++) {
                        if (!(mask & (1 << j))) {
                            int next = mask | (1 << j);
                            if (dp[next][j] == -1 || dp[next][j] > dp[mask][i] + dist[i][j]) {
                                dp[next][j] = dp[mask][i] + dist[i][j];
                            }
                        }
                    }
                }
            }
        }

        int ret = -1;
        int final_mask = (1 << nb) - 1;
        for (int i = 0; i < nb; i++) {
            if (ret == -1 || ret > dp[final_mask][i] + dist[i][nb + 1]){
                ret = dp[final_mask][i] + dist[i][nb + 1];
            }
        }
        return ret;
    }

};