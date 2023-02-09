#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> graph(n);
        for(int i = 0; i < paths.size(); ++i) {
            // 构建图的邻接表
            graph[paths[i][0] - 1].push_back(paths[i][1] - 1);
            graph[paths[i][1] - 1].push_back(paths[i][0] - 1);
        }
        vector<int> ans(n, 0);

        for(int i = 0; i < n; ++i) {
            set<int> color = {1, 2, 3, 4};
            for(int j = 0; j < graph[i].size(); ++j) {
                color.erase(ans[graph[i][j]]);
            }
            ans[i] = *(color.begin());
        }
        return ans;
    }
};