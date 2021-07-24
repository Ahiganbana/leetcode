#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//找到图的拓扑排序
class Solution {
    vector<vector<int>> edge;
    vector<int> visited;
    vector<int> res;
    bool valid = true;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edge.resize(numCourses);
        visited.resize(numCourses);
        //构造边缘列表
        for(auto n : prerequisites) {
            edge[n[1]].push_back(n[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if(!visited[i]) {
                dfs(i);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }

    //对节点n进行深度优先遍历
    void dfs(int n) {
        visited[n] = 1;
        for (auto v : edge[n]) {
            if(visited[v] == 0) {
                //节点没有被访问过,深度优先遍历
                dfs(v);
                if(!valid) {
                    return;
                }
            }else if(visited[v] == 1) {
                //节点已经被访问过一次, 说明图中有环,无法进行拓扑排序
                valid = false;
                res.clear();
                return;
            }
        }
        //节点访问完毕
        res.push_back(n);
        visited[n] = 2;
    }
};
