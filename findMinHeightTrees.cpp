#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//从每个节点开始计算以该节点为根的树的高度
//广度优先遍历需要记录节点的度
class Solution {

public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) {
            return {0};
        }else if(n == 2) {
            return {0, 1};
        }
        vector<vector<int>> newEdges;// 图的邻接矩阵
        vector<int> res;
        vector<int> indegree;
        int height = INT_MAX, iheight = 0;
        newEdges.resize(n);
        indegree.resize(n);
        for (int i = 0; i < edges.size(); i++) {
            newEdges[edges[i][0]].emplace_back(edges[i][1]);
            newEdges[edges[i][1]].emplace_back(edges[i][0]);
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if(indegree[i] == 1) {
                q.push(i);
            }
        }
        int cnt = q.size();
        while(n > 2) {
            n -= cnt;
            while(cnt--) {
                int tmp = q.front();
                q.pop();
                indegree[tmp] = 0;
                //更新tmp的邻接结点,如果度数为1则入队
                for (int i = 0; i < newEdges[tmp].size(); ++i) {
                    if(indegree[newEdges[tmp][i]] != 0) {
                        indegree[newEdges[tmp][i]]--;
                        if(indegree[newEdges[tmp][i]] == 1) {
                            q.push(newEdges[tmp][i]);
                        }
                    }
                }
            }
            cnt = q.size();
        }
        while(!q.empty()) {
            res.emplace_back(q.front());
            q.pop();
        }
        return res;
    }

};


int main() {
    Solution solution;
    int n = 0;
    cin >> n;
    vector<vector<int>> edges(n - 1, vector<int>(2, 0));
    for (int i = 0; i < n - 1; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    vector<int> res = solution.findMinHeightTrees(n, edges);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}