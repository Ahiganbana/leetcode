#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> edges(n + 1, vector<int>(n + 1, -1));
        //从节点k开始到每个节点的距离
        vector<int> res(n + 1, INT_MAX);
        //构造图的邻接矩阵
        for(auto x : times) {
            edges[x[0]][x[1]] = x[2];
        }

        queue<pair<int, int>> q;
        res[k] = 0;
        q.emplace(make_pair(k, 0));
        while(!q.empty()) {
            pair<int, int> tmp = q.front();
            q.pop();
            for (int i = 1; i <= n; ++i) {
                //没有边
                if(edges[tmp.first][i] == -1) {
                    continue;
                }
                if(res[i] > tmp.second + edges[tmp.first][i]) {
                    res[i] = tmp.second + edges[tmp.first][i];
                    q.emplace(make_pair(i, tmp.second + edges[tmp.first][i]));
                }
            }
        }
        for (int i = 1; i < res.size(); i++)
        {
            if(res[i] == INT_MAX){
                return -1;
            }
        }
        return *max_element(res.begin() + 1, res.end());
    }
};

int main() {
    Solution solution;
    int n = 0, k = 0;
    cin >> n >> k;
    vector<vector<int>> times(n, vector<int>(3));
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> times[i][j];
        }
    }
    int result = solution.networkDelayTime(times, n, k);
    cout << result << endl;
    system("pause");
    return 0;
}
/*
4 2
2 1 1
2 3 1
3 4 1
*/